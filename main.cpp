# include <iostream>
# include <fstream>
# include <cstring>
# include <cmath>
# include <algorithm>
# include "bmplib.cpp"
using namespace std ;
unsigned char image[SIZE][SIZE] ;
unsigned char image1[SIZE][SIZE] ;
void load_image() ;
void load_image2() ;
void saveimage ();
void saveimage2() ;
void Black_White() ;
void invert_image() ;
void merge_image() ;
void flibhorizontally() ;
void flib_vertically() ;
void shrink() ;
void blure() ;
void darkenImage ();
void lightenImage ();
void rotate_90degrees() ;
void rotate_180degrees() ;
void rotate_270degrees() ;
void left_mirror();
void right_mirror();
void upper_mirror();
void down_mirror();
void detect_image() ;
void enlarge() ;
void Shuffle();
void Crop();
void skew() ;
int main()
{
    load_image() ;
while(true)
{
    int order ;
    cout << "Please select a filter to apply or 0 to exit \n"
    <<"1- Black &  White filter \n"
    <<"2- Invert filter \n"
    <<"3- Merge filter \n"
    <<"4- Flip image \n"
    <<"5- Darken and Lighten Image \n"
    <<"6- Rotate Image \n"
    <<"7- Detect Image Edges \n"
    <<"8- Enlarge Image \n"
    <<"9- Shrink Image  \n"
    <<"10- Mirror 1/2 Image \n"
    <<"11- Shuffle Image \n"
    <<"12- Blur Image \n"
    <<"13- Crop Image \n"
    <<"14- Skew Image \n"
    <<"S- Save Image \n"
      << "0-Exit\n";
    <<"0- Exit\n";

    cin >> order ;

    switch (order) {
        case 1:
    {
        Black_White() ;
        saveimage() ;
        break;
    }
        case 2:
    {
        invert_image() ;
        saveimage() ;
        break;
    }
    case 3:
    {
        load_image2();
        merge_image() ;
        saveimage() ;
        break;
    }
        case 4:
    {
        int choice ;
        cout << "would you like to :\n"
        << "1-flib image horizontally \n"
        << "2-flib image vertically \n" ;
        cin >> choice ;
        if (choice == 1 )
        {
            flibhorizontally();
            saveimage2() ;
            break;
        }
        else if (choice ==2 )
        {
            flib_vertically() ;
            saveimage2() ;
            break;
        }
    }
        case 5:
    {
        int choice ;
        cout << "Do you want to (d)arken or (l)ighten \n"
        << "1-darken Image \n"
        << "2-lighten Image \n" ;
        cin >> choice ;
        if (choice == 1 )
        {
            darkenImage ();
            saveimage2() ;
            break;
        }
        else if (choice ==2 )
        {
            lightenImage ();
            saveimage2() ;
            break;
        }
    }
        case 6:
    {
        int choice;
    cout << "would you like to :\n"
    <<"1_Rotate (90)  degrees \n"
    <<"2_Rotate (180) degrees \n"
    <<"3_Rotate (270) degrees \n";
    cin>>choice;
    if (choice == 1)
    {
      rotate_90degrees() ;
      saveimage2();
        break;
    }
    else if (choice ==2)
    {
      rotate_180degrees() ;
      saveimage2();
        break;
    }
    else if (choice ==3)
    {
      rotate_270degrees() ;
      saveimage2();
        break;
    }
    }
        case 7:
    {
       detect_image() ;
       saveimage2() ;
        break;
    }
        case 8:
    {
        enlarge() ;
        saveimage2() ;
        break;
    }
        case 9:
    {
        shrink() ;
        saveimage2() ;
        break;
    }
        case 10:
    {
            int choice;
    cout << "Mirror (l)eft, (r)ight, (u)pper, (d)own side?\n"
    <<"1_Mirror left  \n"
    <<"2_Mirror right \n"
    <<"3_Mirror upper \n"
    <<"4_Mirror down  \n";
    cin>>choice;
    if (choice == 1)
    {
      left_mirror();
      saveimage2();
        break;
    }
    else if (choice ==2)
    {
      right_mirror();
      saveimage2();
        break;
    }
    else if (choice ==3)
    {
      upper_mirror();
      saveimage2();
        break;
    }
    else if (choice ==4)
         {
           down_mirror();
           saveimage2();
             break;
         }
    }
        case 11:
    {
    //ShuffleImage() ;
       Shuffle();
    saveimage2();
        break;
    }
        case 12:
    {
        blure() ;
        saveimage2() ;
        break;
    }
        case 13:
        {
            Crop();
            saveimage2();
             break;
        }
        case 14:
    {
        skew();
        saveimage() ;
        break;
    }
        case 's':
    {
        saveimage() ;
        break;
    }
        case 0:
    {
        exit(0);
        break ;
    }
    }
}
}
void load_image()
{
    char filename1[100] ;
    int i ;
    cout << "Please Enter Your File Name: " ;
    cin >> filename1 ;
    strcat (filename1 , ".bmp") ;
    readGSBMP(filename1,image) ;
}
void saveimage ()
{
   char new_file[100];
   cout << "Enter the new file name: ";
   cin >> new_file;
   strcat (new_file, ".bmp");
   writeGSBMP(new_file, image);
}
void saveimage2 ()
{
   char new_file[100];
   cout << "Enter the new file name: ";
   cin >> new_file;
   strcat (new_file, ".bmp");
   writeGSBMP(new_file, image1);
}
void load_image2()
{
    char filename[100] ;
     cout << "Please Enter Your File Name: " ;
        cin >> filename ;
        strcat (filename, ".bmp") ;
        readGSBMP(filename,image1) ;
}
void Black_White()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            if (image[i][j] > 127)
            {
                image[i][j] = 255 ;
            }
            else
            {
                image[i][j] = 0 ;
            }
        }
    }
}
void invert_image()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            if (image[i][j] == 255)
            {
                image[i][j] = 0 ;
            }
            else if (image[i][j] == 0 )
            {
                image[i][j] = 255 ;
            }
            else
            {
                image[i][j] = 255 - image[i][j];
            }
        }
    }
}
void merge_image()
{
   for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           image[i][j] = (image[i][j]+image1[i][j]) / 2 ;
       }
   }
}
void flibhorizontally()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            image1[i][j] = image[i][SIZE-j]  ;
        }
    }
}
void flib_vertically()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            image1[i][j] = image[SIZE-i][j]  ;
        }
    }
}
void shrink()
{
    int skiprow = 0 , skipcolumn = 0 ;
    int shrink_value  , new_size ;
    cout << "enter shrinking value: " ;
    cin >> shrink_value ;
    new_size = SIZE /shrink_value ;
    for (int i = 0; i < new_size ; i ++)
    {
        for (int j = 0 ; j < new_size ; j ++)
        {
               image1[i][j] = image[skiprow][skipcolumn] ;
               skipcolumn += shrink_value ;
        }
        skipcolumn = 0 ;
        skiprow += shrink_value ;
    }
}
void blure()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
           image1[i][j] = (image[i][j] + image[i+1][j] + image[i][j+1] + image[i+1][j+1] + image[i-1][j] + image[i][j-1] + image[i-1][j-1] + image[i+2][j] + image[i][j+2] + image[i+2][j+2] + image[i-2][j] + image[i][j-2] + image[i-2][j-2] + image[i+3][j] + image[i][j+3] + image[i+3][j+3] + image[i-3][j] + image[i][j-3] + image[i-3][j-3]) / 19;
        }
    }
}
void darkenImage()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {
        image1[i][j] =image[i][j]/2 ;
    }
  }
}
void lightenImage ()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {
        image1[i][j] =(image[i][j]+255)/2;
    }
  }
}
void rotate_90degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
        image1[i][j] = image[j][SIZE-i]  ;
       }
   }
}
void rotate_180degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           image1[i][j] =image[SIZE-i-1][SIZE-j-1] ;
       }
   }
}
void rotate_270degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
        image1[i][j]=image[SIZE-j][i];
       }
   }
}
void left_mirror()
{
  for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image1[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                image1[i][j] = image[i][255 - j];
            }
        }
}
void right_mirror()
{
    for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                image1[i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                image1[i][j] = image[i][255 - j];
            }
        }
}
void upper_mirror()
{
  for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1[i][j] = image[i][j];
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1[i][j] = image[255 - i][j];
            }
        }
}
void down_mirror()
{
  for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1 [i][j] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                image1[i][j] = image[255 - i][j];
            }
        }
}
void detect_image()
{
    Black_White() ;
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            if (image[i][j] == image[i][j+1])
            {
                image1[i][j] = 255 ;
            }
            else
            {
                image1[i][j] = 0 ;
            }
        }
    }
}
void enlarge()
{
  int  chioce  ;
  cout << "please choose the quarter which you want to enlarge: " ;
  cin >> chioce ;
  if (chioce == 1)
  {
     for(int i = 0 ; i < SIZE ; i ++ )
     {
    for (int j = 0 ; j < SIZE ; j ++)
      {
         image1[i][j] = image[i/2][j/2] ;
      }
    }
  }
  else if (chioce == 3 )
  {
    for (int i = 0 ; i < SIZE ; i ++)
    {
      for (int j = 0 ; j < SIZE ; j ++)
      {
         image1[i][j] = image[(i/2)+127][j] ;
      }
    }
  }
  else if (chioce == 2)
  {
    for (int i = 0 ; i < 128 ; i ++)
    {
      for (int j = 128 ; j < 256 ; j ++)
      {
         image1[i][j] = image[i][(j/2)+127] ;
      }
    }
  }
  else if (chioce == 4 )
  {
    for (int i =  0 ; i < SIZE; i ++)
    {
      for (int j = 0 ; j < SIZE ; j ++)
      {
         image1[i][j] = image[(i/2)+127][(j/2)+127] ;
      }
    }
  }
}
void Shuffle(){
    bool check=true;
    int q1,q2,q3,q4;
    cout<<"Please enter the order of quarters you want: \n form 1 to 4 \n";
    cin>>q1;
    if(q1==1){
        for(int i=0;i<127;i++){
            for(int j=0;j<127;j++){
                image1[i][j] = image[i][j];
            }
        }
    }
    else if(q1==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                image1[i][j-127] = image[i][j];
            }
        }
    }
    else if(q1==3){
        for(int r=127;r<SIZE;r++){
            for(int j=0;j<127;j++){
                image1[r-127][j] = image[r][j];
            }
        }
    }
    else if(q1==4){
        for(int r=127;r<SIZE;r++){
            for(int j=127;j<SIZE;j++){
                image1[r-127][j-127] = image[r][j];
            }
        }
    }
    cin>>q2;
    if(q2==1){
        for(int r=0;r<127;r++){
            for(int j=0;j<127;j++){
                image1[r][j+127] = image[r][j];
            }
        }
    }
    else if(q2==2){
        for(int r=0;r<127;r++){
            for(int j=127;j<SIZE;j++){
                image1[r][j] = image[r][j];
            }
        }
    }
    else if(q2==3){
        for(int r=127;r<SIZE;r++){
            for(int j=0;j<127;j++){
                image1[r-127][j+127] = image[r][j];
            }
        }
    }
    else if(q2==4){
        for(int r=127;r<SIZE;r++){
            for(int j=127;j<SIZE;j++){
                image1[r-127][j] = image[r][j];
            }
        }
    }
    cin>>q3;
    if(q3==1){
        for(int i=0;i<127;i++){
            for(int j=0;j<127;j++){
                image1[i+127][j] = image[i][j];
            }
        }
    }
    else if(q3==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                image1[i+127][j-127] = image[i][j];
            }
        }
    }
    else if(q3==3){
        for(int i=127;i<SIZE;i++){
            for(int j=0;j<127;j++){
                image1[i][j] = image[i][j];
            }
        }
    }
    else if(q3==4){
        for(int i=127;i<SIZE;i++){
            for(int j=127;j<SIZE;j++){
                image1[i][j-127] = image[i][j];
            }
        }
    }
    cin>>q4;
    if(q4==1){
        for(int i=0;i<127;i++){
            for(int j=0;j<127;j++){
                image1[i+127][j+127] = image[i][j];
            }
        }
    }
    else if(q4==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                image1[i+127][j] = image[i][j];
            }
        }
    }
    else if(q4==3){
        for(int i=127;i<SIZE;i++){
            for(int j=0;j<127;j++){
                image1[i][j+127] = image[i][j];
            }
        }
    }
    else if(q4==4){
        for(int i=127;i<SIZE;i++){
            for(int j=127;j<SIZE;j++){
                image1[i][j] = image[i][j];
            }
        }
    }
    else {
        cin.clear();
        cin.ignore();
        cout<<"Please enter available quarter "<< endl ;
        Shuffle();
    }
}
void skew() {
    string direction;
    cout << "Enter 'h' to skew horizontally or 'v' to skew vertically : ";
    cin >> direction;
    cout << "Enter the degree : \n";
    double rad;
    cin >> rad;
    rad = (rad * 22) / (180 * 7);
    unsigned char shrink[SIZE][SIZE];
    unsigned char skew[SIZE][SIZE];
    int x = (tan(rad) * 256) / (tan(rad) + 1);;
    double step = SIZE - x;
    double move = step / SIZE;
    if (direction == "h") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrink[i][(j * x) / SIZE] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = shrink[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                skew[i][j] = 255;
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = (int) step; j < step + x; j++) {
                skew[i][j] = shrink[i][(int) (j - step)];
            }
            step -= move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = skew[i][j];
            }
        }
    } else if (direction == "v") {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                shrink[j][(i * x) / SIZE] = image[i][j];
            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = shrink[i][j];
            }
        }
        for (int j = 0; j < SIZE; j++) {
            for (int i = 0; i < SIZE; i++) {
                skew[j][i] = 255;
            }
        }
        for (int j = 0; j < SIZE; j++) {
            for (int i = (int) step; i < step + x; i++) {
                skew[i][j] = shrink[j][(int) (i - step)];
            }
            step -= move;
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                image[i][j] = skew[i][j];
            }
        }
    }
}
void  Crop() {
    int x, y, length, width;
    cout << " Enter the x position for cutting: ";
    cin >> x;
    cout << "Enter the y position for cutting: ";
    cin >> y;
    cout << "Enter the square of the length: ";
    cin >> length;
    cout << "Enter the square of width: ";
    cin >> width;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            image1[i][j] = 255;
        }
    }
    for (int i = x; i < length; i++) {
        for (int j = y; j < width; j++) {
            image1[i][j] = image[x + i][y + j];
        }

    }
}
}
