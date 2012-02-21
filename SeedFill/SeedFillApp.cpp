/*	Created by Mark Kleback on 2/21/12.
 *	Copyright 2012 Kleebtronics, Inc. All rights reserved.
 */

#include "SeedFillApp.h"
#include "poApplication.h"
#include "poCamera.h"


// APP CONSTRUCTOR. Create all objects here.
SeedFillApp::SeedFillApp() {
	addModifier(new poCamera2D(poColor::black));
}

// APP DESTRUCTOR. Delete all objects here.
SeedFillApp::~SeedFillApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void SeedFillApp::update() {
	
}

// DRAW. Called once per frame. Draw objects here.
void SeedFillApp::draw() {
	
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void SeedFillApp::eventHandler(poEvent *event) {
	
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void SeedFillApp::messageHandler(const std::string &msg, const poDictionary& dict) {
	
}
