/*	Created by Mark Kleback on 2/21/12.
 *	Copyright 2012 Kleebtronics, Inc. All rights reserved.
 */

#include "SeedFillApp.h"
#include "poApplication.h"
#include "poCamera.h"
#include <iostream>
#include "poObject.h"
#include "poImageShape.h"
#include "smImage.h"
#include "poTextBox.h"
#include "poFont.h"

using namespace po;
using namespace std;


// APP CONSTRUCTOR. Create all objects here.
SeedFillApp::SeedFillApp() {
	addModifier(new poCamera2D(poColor::black));
    
    
    
    myImage1 = new smImage("flood_fill_test_01.raw", 320, 240);
    myImage2 = new smImage("flood_fill_test_02.raw", 320, 240);
    myImage3 = new smImage("flood_fill_test_03.raw", 320, 240);
    
    currentImage1 = new smImage(320, 240);
    currentImage2 = new smImage(320, 240);
    
    currentImage1 = myImage1;
   

    
    
    addEvent( PO_MOUSE_MOVE_EVENT, this );
    addEvent( PO_KEY_DOWN_EVENT, this );
    addEvent( PO_KEY_UP_EVENT, this);
    
    
}

// APP DESTRUCTOR. Delete all objects here.
SeedFillApp::~SeedFillApp() {
}

// UPDATE. Called once per frame. Animate objects here.
void SeedFillApp::update() {
    
    
    
    for( int x = 0; x< currentImage2->width; x++)
    {
        for(int y = 0; y< currentImage2->height; y++)
        {
            
            
            
            currentImage2->setPixel(x, y, 0);
            
            
        }
    }
    

    
    
    int label = 50;
    int counter = 1;
    
    for (int i=0; i < currentImage1->width; i++)
    {
        for (int j = 0; j < currentImage1->height; j++){
            
           
            
            if(currentImage1->getPixel(i,j) != 0){
            
            seedFill(i,j,label);
                
                
                //text box
                
                                
                
                label+=50;
        
            }
                
        }
        
    }

    
    
    
    
	
}

// DRAW. Called once per frame. Draw objects here.
void SeedFillApp::draw() {
    
    currentImage1->fastDraw(10, 10);
    currentImage2->fastDraw(400, 10);
	
}

// EVENT HANDLER. Called when events happen. Respond to events here.
void SeedFillApp::eventHandler(poEvent *event) {
	
    
    if ( event->type == PO_MOUSE_MOVE_EVENT )
    {
        mouseX = event->globalPosition.x;
        mouseY = event->globalPosition.y;
    }
    
    if ( event->type == PO_KEY_DOWN_EVENT )
    {
        lastKeyDown = event->keyChar;
        
        
        if(lastKeyDown == '1'){
            currentImage1 = myImage1;
        }
        
        if(lastKeyDown == '2'){
            currentImage1 = myImage2;
           
        }
        
        if(lastKeyDown == '3'){
            currentImage1 = myImage3;
           
        }
        
        
        
    }
    
    
    

    
    
}

// MESSAGE HANDLER. Called from within the app. Use for message passing.
void SeedFillApp::messageHandler(const std::string &msg, const poDictionary& dict) {
	
}


void SeedFillApp::seedFill(int x, int y, int label)
{
    
    if(currentImage1->getPixel(x,y) == 0){
        return;
    }
    
    if(currentImage2->getPixel(x,y) !=0){
        return;
    }
    
  
    
    currentImage2->setPixel(x, y, label);
    
    seedFill(x, y-1, label);
    seedFill(x+1, y, label);
    seedFill(x, y+1, label);
    seedFill(x-1, y, label);
    
//    stringstream sstm;
//    
//    
//    A = new poTextBox();	 // Specify the width and height of the text box (optional)
//    
//    A->setFont( poGetFont("Helvetica", "Regular") );	// Set the font, always
//    
//    // You can create a new poFont by calling poGetFont("FontFamilyName", "FontStyle")
//    
//    // Make sure the font is installed in your machine
//    
//    A->setTextSize(18);	 // Set the text size
//    A->textColor = poColor::red;	 // Set the text color
//    A->doLayout();	 // Always call doLayout() after you make any change
//    
//    addChild( A );
//    
//    
//    sstm << " " << label/50 ;
//    // Specify the width and height of the text box (optional)
//    A->position.set(x, y , 0);
//    A->setText(sstm.str());		// Set the text
//    // Set the text color
//    A->doLayout();	
//
//    
//        
   
    
    
    
}