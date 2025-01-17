#include "BouncingBall.h"
#include "cinder/Rand.h"

using namespace ci;

BouncingBall::BouncingBall( const vec3 &position ){
    
    mPosition = position;
    mSpeed = randVec3();
    mSize = randFloat( 3,5 );
    
    mBall = gl::Batch::create(
                              geom::Sphere().radius(mSize),
                              gl::getStockShader(gl::ShaderDef().lambert())
                              );
}

BouncingBallRef BouncingBall::create(const ci::vec3 &position){
    
    return BouncingBallRef( new BouncingBall( position) );
    
}

void BouncingBall::update(){
    
    mPosition += mSpeed;
    
}

void BouncingBall::draw(){
    
    gl::ScopedModelMatrix pushModel;
    
    gl::translate(mPosition);
    
    mBall->draw();
    
}

void BouncingBall::checkBounds(ci::AxisAlignedBox &box){
    
    if ( !box.contains(mPosition) ) {
        mSpeed = -mSpeed;
    }
    
}