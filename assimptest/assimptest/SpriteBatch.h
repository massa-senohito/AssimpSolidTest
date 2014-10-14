#include "stdafx.h"
//http://d.hatena.ne.jp/setuna-kanata/20100721/1279731858/
template< typename Vertex >
class VertexBuffer
  : public BufferObject
{
public:
  /**
  *  頂点配列でバッファを更新
  */
  void update(int offset, int vertex_count, const Vertex* vertex)
  {
    BufferObject::update(offset, sizeof(Vertex), vertex_count, vertex);
  }

public:
  /**
  *  頂点配列でバッファの生成、初期化を行う。
  *  vertexにnullptrを指定した場合、vertex_countのサイズでバッファの生成のみ行う。
  *
  *  @param  vertex_count    頂点数
  *  @param  vertex          頂点配列の先頭アドレス
  */
  VertexBuffer(int vertex_count, const Vertex* vertex = nullptr)
    : BufferObject(GL_ARRAY_BUFFER_ARB, sizeof(Vertex), vertex_count, vertex)
  {
  }

};

struct SpriteBatchVertex
{
  float x, y;         ///<    とりあえず2D
  float r, g, b, a;   ///<    unsigned charの方が良いかも
  float tu, tv;       ///<    テクスチャ座標
};
//
//class SpriteBatch
//{
//public:
//  /**
//  *  頂点バッファにスプライトを追加。
//  */
//  void add(const TexturePtr& texture, const Recti& rect, const Color& color);
//  /**
//  *  頂点バッファに溜められているスプライトをまとめて描画。
//  */
//  void draw();
//
//public:
//  SpriteBatch(GLushort sprite_count);
//
//private:
//  VertexBuffer< SpriteBatchVertex > vertex;   ///<    sprite_count * 4個の頂点
//  IndexBuffer index;                          ///<    sprite_count * 6個のインデックス
//  int current;                                ///<    現在のスプライト数
//  int sprite_count;                           ///<    スプライトの最大数
//  std::shared_ptr< OpenGLTexture > texture;   ///<    現在のスプライトで使われているテクスチャ
//};
//