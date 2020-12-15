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

bool Collision::checkCollisionCollideables(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> collideables){
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();

   //b2 = two->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   //two->getRelativeTransformation().transformBoxEx( b2 );
   for(unsigned int i = 0; i < collideables.size();i++){
      if(collideables[i] != one){
         b2 = collideables[i]->getBoundingBox();
         collideables[i]->getRelativeTransformation().transformBoxEx(b2);
         if(b1.intersectsWithBox(b2)){
            return true;
         }
      }
   }
   return false;
}

/*bool Collision::checkCollisionWalls(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p){
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
}*/

/*bool Collision::checkCollisionWallsAnim(irr::scene::ISceneManager* smgr,irr::scene::ISceneNode* one, std::vector<irr::scene::ISceneNode*> p){
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
}*/

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

bool Collision::checkCollisionOneEnemy(irr::scene::ISceneNode* one, irr::scene::ISceneNode* enemy){
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = one->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   one->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }

   return col;
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

bool Collision::checkCollisionEspada(irr::scene::ISceneNode* cube_player, irr::scene::ISceneNode* enemy, int direction){
   irr::core::vector3df pos = cube_player->getPosition();
   irr::core::vector3df posPrueba = pos;
   // Comprobamos la dirección para establecer la posición de la espada

   if(direction == 1)
      posPrueba.X += 3;
   else if(direction == 2)
      posPrueba.X -= 3;
   else if(direction == 3)
      posPrueba.Z += 3;
   else if(direction == 4)
      posPrueba.Z -= 3;
   else if(direction == 5){
      posPrueba.X += 3;
      posPrueba.Z += 3;
   }
   else if(direction == 6){
      posPrueba.X -= 3;
      posPrueba.Z += 3;
   }
   else if(direction == 7){
      posPrueba.X += 3;
      posPrueba.Z -= 3;
   }
   else if(direction == 8){
      posPrueba.X -= 3;
      posPrueba.Z -= 3;
   }

   cube_player->setPosition(posPrueba);
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = cube_player->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   cube_player->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   cube_player->setPosition(pos);
   
   return col;
}

bool Collision::checkPressedButton(irr::scene::ISceneNode* draggable, std::vector<irr::scene::ISceneNode*> buttons){
   irr::core::vector3df posButton;
   irr::core::aabbox3d<irr::f32> b1, b2;

   b1 = draggable->getBoundingBox ();
   draggable->getRelativeTransformation().transformBoxEx( b1 );
   
   for(unsigned int i = 0; i < buttons.size();i++){
      posButton = buttons[i]->getPosition();
      b2 = buttons[i]->getBoundingBox ();
      buttons[i]->getRelativeTransformation().transformBoxEx( b2 );
      if(b1.intersectsWithBox(b2)){
         draggable->setPosition(posButton);
         return true;
      }
   }
   return false;
}

bool Collision::checkCollisionBomba(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* enemy){
   bomba->setScale(irr::core::vector3df(6.0f,6.0f,6.0f));
   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = bomba->getBoundingBox ();
   b2 = enemy->getBoundingBox ();

   bomba->getRelativeTransformation().transformBoxEx( b1 );
   enemy->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   return col;
}

bool Collision::checkCollisionPlayerBomb(irr::scene::ISceneNode* bomba, irr::scene::ISceneNode* cube_player){
   bomba->setScale(irr::core::vector3df(6.0f,6.0f,6.0f));

   bool col = false;
   irr::core::aabbox3d<irr::f32> b1, b2;
   
   b1 = bomba->getBoundingBox ();
   b2 = cube_player->getBoundingBox ();

   bomba->getRelativeTransformation().transformBoxEx( b1 );
   cube_player->getRelativeTransformation().transformBoxEx( b2 );
   
   if(b1.intersectsWithBox(b2)){
      col = true;
   }
   return col;
}
