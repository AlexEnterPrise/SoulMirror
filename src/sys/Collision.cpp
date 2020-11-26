#include "Collision.hpp"

Collision::Collision(){

}

bool Collision::checkCollision(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two){
   irr::core::aabbox3d<irr::f32> b1, b2;

   b1 = one->getBoundingBox ();
   b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return b1.intersectsWithBox( b2 );
}