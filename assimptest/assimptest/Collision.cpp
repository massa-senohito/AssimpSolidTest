#include "stdafx.h"
#include "Collision.h"
#include "include\GL\freeglut.h"
#define let auto

Collision::Collision()
{
  scene = DT_CreateScene();
}
void Collision::AddPoint(float v[3]){
	let	base = DT_NewVertexBase   (v, 0);
  let shape= DT_NewComplexShape (base);
  //どうにもsetShapeしても木は構築されない、sample
  //
  //solid-3.5.7\src\complex\DT_BBoxTree
  //DT_Complex
  DT_VertexRange     (0, 1);
  DT_EndComplexShape ();

  DT_Begin  ();
  DT_Vertex (v);
  DT_End    ();
}
void AddBox(float v[8]){
  //DT_NewBox(v[0], v[1], v[2]);
	let	base = DT_NewVertexBase  (v, 0);
  let shape=DT_NewComplexShape (base);

  DT_VertexRange (0, 8);
	
  DT_EndComplexShape();
  //構成のためのインデックスを置く
}
void writeResult(cstring rpath,Verts& v){
  //自動的にresultに書かれる、フラグで
}
Verts& readResult(cstring rpath){
  FILE* fp;
  //auto rpath = "C:\\Users\\master8\\Downloads\\solid-3.5.7\\result";
  let err=fopen_s(&fp, rpath, "rb");
  Verts& v = *(new std::vector<float>);
  if (!err){
    int* len=new int;
    fread_s(len, sizeof len, 4, 1, fp);
    int l = *len;
    float* cenext=new float[6*l];
    auto fl = sizeof(float);
    for (size_t i = 0; i < l; i+=6)
    {
      fread_s(&cenext[i], fl*6, fl*6, 1, fp); //l countロードすれば一気に
      v.push_back(cenext[i]);
      v.push_back(cenext[i+1]);
      v.push_back(cenext[i+2]);
      v.push_back(cenext[i+3]);
      v.push_back(cenext[i+4]);
      v.push_back(cenext[i+5]);
    }
    fclose(fp);
    delete len;
    delete cenext;
  }
  return v;
}
#define adec(a,s) a[s+i],a[s+1+i],a[s+2+i]
void Collision::RenderTree(){
  static let path = "C:\\Users\\master8\\Documents\\Visual Studio 2013\\Projects\\assimptest\\assimptest\\result";
  if (verts){
    let len = verts->size();
    for (size_t i = 0; i < len; i+=6)
    {
      let el = verts[i];
      //初めの3要素は座標、後ろがextent
      glTranslatef(adec(el,0));
      glScalef    (adec(el,3));
      glutWireCube(1);
    }
  }
  else{
    verts = &readResult("C:\\");
    RenderTree();
  }
}
Collision::~Collision()
{
  DT_DestroyScene(scene);
}
