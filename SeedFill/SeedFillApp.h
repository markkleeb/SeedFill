/*	Created by Mark Kleback on 2/21/12.
 *	Copyright 2012 Kleebtronics, Inc. All rights reserved.
 */

#include "poObject.h"
#include "smImage.h"
#include "poImageShape.h"
#include "poTextBox.h"
#include <iostream>

class SeedFillApp : public poObject {
public:
    
	SeedFillApp();
	virtual ~SeedFillApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());


    
    smImage* myImage1;
    smImage* myImage2;
    smImage* myImage3;
    
    smImage* currentImage1;
    smImage* currentImage2;
    
    float   mouseX, mouseY;
    int     threshold;
    char    lastKeyDown;
    
    poTextBox* A;


    
    void    seedFill(int x, int y, int label);
    
    
};

