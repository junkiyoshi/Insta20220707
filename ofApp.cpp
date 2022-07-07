#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(0);
	ofSetColor(255);
	ofNoFill();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);
	
	for (int base_deg = 0; base_deg < 360; base_deg += 2) {

		vector<glm::vec2> vertices;
		auto base_radius = ofRandom(720);
		auto speed = ofRandom(3, 5);
		ofSetLineWidth(ofRandom(0.5, 3));

		for (int i = 0; i < 30; i++) {

			auto deg = base_deg + (ofGetFrameNum() + i) * 3;
			auto radius = 800 - (int)(base_radius + (ofGetFrameNum() + i) * speed) % 800;
			if (radius > 650) { continue; }
			auto vertex = glm::vec2(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
			vertices.push_back(vertex);
		}

		ofBeginShape();
		ofVertices(vertices);
		ofEndShape();		
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}