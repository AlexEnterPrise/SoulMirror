#include "Collision.hpp"



Collision::Collision(){

}

bool Collision::checkCollision(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two){
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();

   b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   two->getRelativeTransformation().transformBoxEx( b2 );
   return b1.intersectsWithBox( b2 );
   //irr::scene::ITriangleSelector* selector = 0;
//
   //selector = smgr->createTriangleSelectorFromBoundingBox(one);
//
   //if(selector){
   //   const irr::core::aabbox3d<irr::f32>& box = two->getBoundingBox();
   //   irr::core::vector3df radius = box.MaxEdge - box.getCenter();
   //   irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector,two,radius,
   //         irr::core::vector3df(0,0,0), irr::core::vector3df(0,30,0));
   //   selector->drop(); 
   //   return true;
   //}
   //return false;
}

void Collision::createCollisionMoving(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two){
    irr::scene::ITriangleSelector* selector = 0;

   selector = smgr->createTriangleSelectorFromBoundingBox(one);
   
   if(selector){
      const irr::core::aabbox3d<irr::f32>& box = one->getBoundingBox();
      irr::core::vector3df radius = box.MaxEdge - box.getCenter();
      irr::scene::ISceneNodeAnimator* anim = smgr->createCollisionResponseAnimator(selector,one,radius,
            irr::core::vector3df(0,0,0), irr::core::vector3df(0,30,0));
      selector->drop(); 
      one->addAnimator(anim);
      anim->drop();
   }
}