#ifndef __lc_minimap_h__
#define __lc_minimap_h__

#include "gui/Component.hpp"
#include "gui/Color.hpp"
#include "lincity/lin-city.h"
#include "gui/Texture.hpp"

class XmlReader;
class Button;

class MiniMap:public Component
{
 public:

  enum DisplayMode {NORMAL,POLLUTION,UB40,STARVE,POWER,FIRE,CRICKET,HEALTH,COAL,MAX};

  MiniMap(Component *parent, XmlReader& reader);
  
  // colors must be corrected somehow - maybe get them from oldgui/screen.cc
  virtual void draw(Painter &painter);

  virtual void event(const Event& event);
  
  void chooseButtonClicked(Button* button);

 private:

  Color getColor(int x,int y) const;
  Color getColorNormal(int x,int y) const;
  void attachButtons();
  Component *findRoot(Component *c);


  short mappointoldtype[WORLD_SIDE_LEN][WORLD_SIDE_LEN];

  DisplayMode mMode;

  int tilesize;
  int border;

  std::auto_ptr<Texture> mTexture;

  bool mFullRefresh;
  bool alreadyAttached;
};

#endif