#include "Collision.hpp"



Collision::Collision(){

}

bool Collision::checkCollision(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, irr::scene::ISceneNode* two){
   irr::core::aabbox3d<irr::f32> b1, b2, b3;
   
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


bool Collision::checkCollisionWalls(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p){
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();

   //b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   //two->getRelativeTransformation().transformBoxEx( b2 );
   for(unsigned int i = 0; i < p.size();i++){
      b2 = p[i]->getBoundingBox();
      p[i]->getRelativeTransformation().transformBoxEx(b2);
      if(b1.intersectsWithBox(b2)){
         return true;
      }
   }
   return false;
}

bool Collision::checkCollisionWallsAnim(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p){
   irr::core::vector3df posCube = one->getPosition();
   bool col = false;

   for(unsigned int i = 0; i < p.size();i++){
      irr::core::vector3df posCubeM = irr::core::vector3df(posCube.X+2.0,posCube.Y,posCube.Z);
      one->setPosition(posCubeM);
      if(checkCollision(smgr,one,p[i]))
      col = true;

      posCubeM = irr::core::vector3df(posCube.X-2.0,posCube.Y,posCube.Z);
      one->setPosition(posCubeM);
      if(checkCollision(smgr,one,p[i]))
      col = true;

      posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z+2.0);
      one->setPosition(posCubeM);
      if(checkCollision(smgr,one,p[i]))
      col = true;

      posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z-2.0);
      one->setPosition(posCubeM);
      if(checkCollision(smgr,one,p[i]))
      col = true;
   }

   one->setPosition(posCube);
   return col;
}

bool Collision::checkCollisionEnemies(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p){
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();

   //b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   //two->getRelativeTransformation().transformBoxEx( b2 );
   for(unsigned int i = 0; i < p.size();i++){
      b2 = p[i]->getBoundingBox();
      p[i]->getRelativeTransformation().transformBoxEx(b2);
      if(b1.intersectsWithBox(b2)){
         return true;
      }
   }
   return false;
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

bool Collision::checkCollisionObject(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* object){
       irr::core::vector3df posCube = cube_player->getPosition();
       bool col = false;

       irr::core::vector3df posCubeM = irr::core::vector3df(posCube.X+0.5,posCube.Y,posCube.Z);
       cube_player->setPosition(posCubeM);
       if(checkCollision(smgr,cube_player,object))
         col = true;

       posCubeM = irr::core::vector3df(posCube.X-0.5,posCube.Y,posCube.Z);
       cube_player->setPosition(posCubeM);
       if(checkCollision(smgr,cube_player,object))
         col = true;

       posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z+0.5);
       cube_player->setPosition(posCubeM);
       if(checkCollision(smgr,cube_player,object))
         col = true;

       posCubeM = irr::core::vector3df(posCube.X,posCube.Y,posCube.Z-0.5);
       cube_player->setPosition(posCubeM);
       if(checkCollision(smgr,cube_player,object))
         col = true;

      cube_player->setPosition(posCube);
      return col;
    }