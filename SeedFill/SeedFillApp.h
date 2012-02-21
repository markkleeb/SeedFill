/*	Created by Mark Kleback on 2/21/12.
 *	Copyright 2012 Kleebtronics, Inc. All rights reserved.
 */

#include "poObject.h"

class SeedFillApp : public poObject {
public:
	SeedFillApp();
	virtual ~SeedFillApp();
	
    virtual void update();
    
    virtual void draw();
	
    virtual void eventHandler(poEvent *event);
	
    virtual void messageHandler(const std::string &msg, const poDictionary& dict=poDictionary());
};

