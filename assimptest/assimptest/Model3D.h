#pragma once
#include "Object3D.h"
#include "assimp\scene.h"
typedef std::string string;
typedef const char* cstring;
class Model3D 
  //:public Object3D
{
  class Impl;
  Impl *impl;
  void setTexname(aiString&);
  aiMesh** meshs;
  int mcount;
  int texCount();
  const aiScene& scene;
public:
  Model3D(cstring);
  bool LoadTexture(aiScene* sc);
  void Dump();
  void Render();
  virtual ~Model3D();
};

