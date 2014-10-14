#include "stdafx.h"
#include "Model3D.h"
#include "assimp\scene.h"
#include "assimp\cimport.h"
#include <assimp/postprocess.h>
#include "include\GL\freeglut.h"
typedef std::map<aiString*, GLuint*> TexIDMap;
typedef aiVector3t<float> V3;
typedef std::list<V3*> Vlist;
class Model3D::Impl
{
public:
  Impl();
  ~Impl();
  int VertCount();
  TexIDMap* textureIDMap;
  void GenTex();
  void Bind(int);
  void AddVert(V3&);
  void ForEachVert(std::function<void(V3&)>);
private:
  GLuint* textures;
  int texCount;
  Vlist* vlist;
};
Model3D::Impl::Impl() :textureIDMap(new TexIDMap()),vlist(new Vlist)

{

}

Model3D::Impl::~Impl()
{
  glDeleteTextures(texCount,textures);
  textureIDMap->clear();
  delete (&textureIDMap);
  //&textureIDMap = nullptr;
}
void Model3D::Impl::GenTex(){
  texCount = textureIDMap->size();
  assert(texCount!= 0);
  textures = new GLuint[texCount];
  glGenTextures(texCount, textures);
}
void Model3D::Impl::Bind(int id){
  glBindTexture(GL_TEXTURE_2D,textures[id]);
}
int Model3D::Impl::VertCount(){
  return vlist->size();
}
void Model3D::Impl::AddVert(V3& v){
  vlist->push_back(&v);
}

void Model3D::Impl::ForEachVert(std::function<void(V3&)> f){
  for (auto i = vlist->begin(); i != vlist->end(); i++){
    f(**i);
  }
}

bool Model3D::LoadTexture(aiScene* sc)
{
  if (sc->HasTextures()){
    let ms=sc->mNumMaterials;
    int texIndex = 0;
    aiString path;
    for (size_t i = 0; i < ms; i++)
    {
      aiReturn res=AI_SUCCESS;
      while(res==AI_SUCCESS){
        //uv座標の配列、マッピング（ボックスに貼るか、柱に貼るか）、モード（テクスチャを繰り返すか1個きりか）、
        //ブレンド方法(足し算引き算)ブレンド率も取れる
        res = sc->mMaterials[i]->GetTexture(aiTextureType_DIFFUSE, texIndex, &path);
        setTexname(path);
        texIndex++;
      }
    }
    return true;
  }
  else return false;
}
void Model3D::setTexname(aiString& path){
  //textureIDMap[path.data] = NULL; //fill map with textures, pointers still NULL yet
  auto p = &path;
  impl->textureIDMap->at(&path) = nullptr;
}
int Model3D::texCount(){
  return impl->textureIDMap->size();
}
Model3D::Model3D(cstring path) :scene(*aiImportFile(path, aiProcessPreset_TargetRealtime_Fast))
{
  meshs = scene.mMeshes;
  //element配列
  meshs[0]->mFaces[0].mIndices;
  mcount=scene.mNumMeshes;
}
void Model3D::Dump(){
  FILE* fp;
  auto er = fopen_s(&fp, "result", "wb");
  //if(er)
  auto nc = impl->VertCount();
  fwrite( &nc,sizeof(int), 1,fp);
  impl->ForEachVert([&fp](V3& i)
  {
#define MT_Scalar float
    auto c = (i);
    fwrite(&c.x, sizeof(MT_Scalar), 1, fp);
    fwrite(&c.y, sizeof(MT_Scalar), 1, fp);
    fwrite(&c.z, sizeof(MT_Scalar), 1, fp);
  });
  fclose(fp);
  
}
#define vdec(v) v.x,v.y,v.z
void Model3D::Render(){
  //後でimplに実装しなおす

  for (size_t m = 0; m < mcount; m++)
  {
    glBegin(GL_QUADS);
    let verts = meshs[m]->mNumVertices;
    let mesh = meshs[m];
    //本当はfacesごとに
    for (size_t i = 0; i < verts; i++)
    {
      let v = mesh->mVertices[i];
      //pointやラインプリミティブなら法線は存在しない
      mesh->mNormals;
      //impl->AddVert(v);
      glVertex3f(vdec(v));
    }
    glEnd();
  }
}
Model3D::~Model3D()
{
  aiReleaseImport(&scene);
}
