//  smImage.cpp
//  spatialMedia


#include <iostream>
#include "smImage.h"
#include "poSimpleDrawing.h"
#include "poApplication.h"


smImage::smImage( const char* fileName, int W, int H )
{  
    // set the image width and height
    width = W;
    height = H;
    
    // load in the image data from file
    FILE* F = fopen( fileName, "rb" );                  // open a file
    if ( F==NULL )
    {
        printf("ERROR: can't find file: %s\n", fileName );
        exit(0);
    }
    imageData = new unsigned char [ width*height ];     // allocate memory for the image
    fread( imageData, 1, width*height, F );             // read file date into the memory
    fclose( F );                                        // close the file
    
    // used for fastDraw method
    imageAsTexture = new poTexture( width, height, imageData, poTextureConfig(GL_LUMINANCE) );
}

smImage::smImage( int W, int H )
{
    // set the image width and height
    width = W;
    height = H;
    
    // load in the image data from file
    imageData = new unsigned char [ width*height ];     // allocate memory for the image
    memset( imageData, 255, width*height );
    
    // used for fastDraw method
    imageAsTexture = new poTexture( width, height, imageData, poTextureConfig(GL_LUMINANCE) );
}

int     smImage::getPixel( int x, int y )
{
    int index = x + y*width;                    // calculate the pixel index
    if ( index < 0 || index >= width*height )
    {
        printf("ERROR: getPixel out of bounds\n");
        return 0;
    }
    return imageData[index];                    // return the pixel
}

void    smImage::setPixel( int x, int y, int grayValue )
{
    int index = x + y*width;                    // calculate the pixel index
    if ( index < 0 || index >= width*height )
    {
        printf("ERROR: setPixel out of bounds\n");
        return 0;
    }
    imageData[index] = grayValue;               // set the pixel
}

void    smImage::draw()
{
    // this is an inefficent, but simple mode of drawing an image
    // we draw one rectangle for every pixel
    // use the fastDraw() method if you want something faster
    for( int x=0; x<width; x++ )
    {
        for( int y=0; y<height; y++ )
        {
            float grayValue = getPixel(x,y);            // get the gray value
            grayValue = grayValue / 255;                // convert from 0-255 to 0.0-1.0
            po::setColor( poColor( grayValue, grayValue, grayValue) );  // set the color
            po::drawFilledRect( x*5,y*5, 5, 5 );        // draw the "pixel" rectangle
        }
    }
}

void    smImage::fastDraw( float x, float y )
{
    // replace the image data int the texture
    imageAsTexture->replace( imageData );
    // draw the texture
    po::drawTexturedRect( imageAsTexture, poRect(x+0,y+height,width,-height) );
}





void    smImage::invert()
{
    
    for( int x = 0; x< width; x++)
    {
        for(int y = 0; y<height; y++)
        {
            
            float grayValue = getPixel(x, y);
            grayValue = 255-grayValue;
            setPixel(x, y, grayValue);
        
            
            
        }
    }

}


void smImage::flipVertical()
{
    tempImage = new unsigned char[ width*height];
    
    for( int x =0; x< width; x++)
    {
        for(int y=0; y<height; y++)
        {
             
            
            float grayValue = getPixel(x, y);
        
            int newindex = x + (height-y)*width;
     
            tempImage[newindex]= grayValue;
            
            
            
        }
    }
            for(int x = 0; x<width; x++)
            {
                for(int y = 0; y<height; y++)
                {
                    int index = x +y*width;
                    
                    setPixel(x, y, tempImage[x+y*width]);
                    
                }
            }
           
            
        
    
}

void smImage::blackandwhite()
{
    
    for( int x = 0; x< width; x++)
    {
        for(int y = 0; y<height; y++)
        {
            
            float grayValue = getPixel(x,y);
            
            if(grayValue > 255/2){
                grayValue = 255;
            }
            else
            {
                grayValue = 0;
            }
            grayValue = grayValue / 255;                // convert from 0-255 to 0.0-1.0
            po::setColor( poColor( grayValue, grayValue, grayValue) );  // set the color
            po::drawFilledRect( x*5,y*5, 5, 5 );        // draw the "pixel" rectangle
            
        }
    }

    
    
}


void smImage::threshold(float _T)
{
    
    float T = (_T*255)/getWindowWidth();
    
    
    for( int x = 0; x< width; x++)
    {
        for(int y = 0; y<height; y++)
        {
            float grayValue = getPixel(x,y);
            
         
            
            if(grayValue > T){
                
                grayValue = 255;
            }
            else{
                grayValue = 0;
                
            }
            
            grayValue = grayValue / 255;                // convert from 0-255 to 0.0-1.0
            po::setColor( poColor( grayValue, grayValue, grayValue) );  // set the color
            po::drawFilledRect( x*5,y*5, 5, 5 );        // draw the "pixel" rectangle
            
        }
    }
    
   }

void smImage::edgeDetect(float _T)

{
    
    float T = (_T*255)/getWindowWidth();
   
    
    for( int x = 0; x< width; x++)
    {
        for(int y = 0; y<height; y++)
        {
             int index = x +y*width;
            int nextIndex = index+1;
        
            if(nextIndex == width*height){
                
                nextIndex = 0;
                
            }

           
            
            float grayValue = getPixel(x,y);
            
            if(abs(imageData[index]-imageData[nextIndex]) > T)
            {
                
                grayValue = 0;
                
            }
            else{
                grayValue = 255;
            }
               
         
            grayValue = grayValue / 255;                // convert from 0-255 to 0.0-1.0
            po::setColor( poColor( grayValue, grayValue, grayValue) );  // set the color
            po::drawFilledRect( x*5,y*5, 5, 5 );        // draw the "pixel" rectangle
            
            
        }
    }

    
    
}

bool smImage::somethingThere(int x0, int y0, int x1, int y1)
{
    
   
    
    int count = 0;
    
    for(int i = 0; i < x1; i ++){
        for(int j = 0; j < y1; j++){
            
           float grayValue = getPixel(i,j);
            
            if(grayValue == 0)
                count ++;
            
        }
    }
    
    if(count > 50)
        return(true);
    else
        return(false);

    

    
    
}












