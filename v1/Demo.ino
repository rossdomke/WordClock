void NoMaskRain(){
  None();
  Colors[CurrentColor]();
  if(b3.CheckButton()){
    DeferToColor();
  }
}
void RandomMask(){
  Random();
  Colors[CurrentColor]();
  if(b3.CheckButton()){
    CurrentColor = (CurrentColor + 1) % 3;
    DeferToColor();  
  }
}

