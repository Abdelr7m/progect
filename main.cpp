/*
Moneeb musa ibrahim faraj - 20210725 - nebomusa1956@gmail.com
Hisham Ibrahim Abdaljader Abualfatah 20210739 - hishamabualfatah@gmail.com
Abdelrhman Abdalsalam Hanfi Gad - 20210890 - abdelrhmanhanfi@gmail.com

*/


# include <iostream>
# include <fstream>
# include <cstring>
# include <cmath>
# include <algorithm>
# include "bmplib.cpp"
using namespace std ;

unsigned char image[SIZE][SIZE][RGB] ;
unsigned char image1[SIZE][SIZE][RGB] ;

void load_image1() ;
void load_image2() ;
void save_image2() ;
void flibing_vertically() ;
void flibing_horizontally() ;
void gray_image() ;
void Black_White() ;
void shrink() ;
void invert_image() ;
void merge_image() ;
void blure_image() ;
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
void ShuffleImage()  ;

int main()
{
    while(true)
{
    char order ;
    cout << "Please selcet a filter to apply or 0 to exit \n"
    << "1- Black &  White filter \n"
    << "2- Invert filter \n"
    << "3- Merge filter \n"
    << "4- Flib image \n"
    <<"5- Darken and Lighten Image \n"
    << "6-Rotate Image \n"
    <<"7_ Detect Image Edges \n"
    <<"8_Enlarge Image \n"
    <<"9_ Shrink Image  \n"
    << "a- Mirror 1/2 Image \n"
    << "b- Shuffle Image \n"
    << "c- Blur Image \n" ;


    cin >> order ;
    if (order == '1' )
    {
        load_image1();
        Black_White() ;
        save_image2() ;
    }

    else if (order =='2' )
    {
        load_image1() ;
        invert_image() ;
        save_image2() ;
    }

    else if (order == '3' )
    {
        load_image1() ;
        load_image2();
        merge_image() ;
        save_image2() ;
    }

    else if (order== '4')
    {
        int choice ;
        cout << "would you like to :\n"
        << "1-flib image horizontally \n"
        << "2-flib image vertically \n" ;
        cin >> choice ;

        if (choice == 1 )
        {
            load_image1() ;
            flibing_horizontally();
            save_image2() ;
        }
        else if (choice ==2 )
        {
            load_image1() ;
            flibing_vertically() ;
            save_image2() ;
        }
    }


    else if (order == '5' )
    {
        int choice ;
        cout << "Do you want to (d)arken or (l)ighten \n"
        << "1-darken Image \n"
        << "2-lighten Image \n" ;
        cin >> choice ;

        if (choice == 1 )
        {
            load_image1() ;
            darkenImage ();
            save_image2() ;
        }
        else if (choice ==2 )
        {
            load_image1() ;
            lightenImage ();
            save_image2() ;
        }
    }


    else if (order == '6')
    {
        int choice;
    cout << "would you like to :\n"
    <<"1_Rotate (90)  degrees \n"
    <<"2_Rotate (180) degrees \n"
    <<"3_Rotate (270) degrees \n";
    cin>>choice;
    if (choice == 1)
    {
      load_image1();
      rotate_90degrees() ;
      save_image2();
    }
    else if (choice ==2)
    {
      load_image1();
      rotate_180degrees() ;
      save_image2();
    }
        else if (choice ==3)
    {
      load_image1();
      rotate_270degrees() ;
      save_image2();
    }

    }
    else if (order== '7')
    {
        load_image1() ;
        detect_image();
        save_image2() ;
    }


    else if (order == '8' )
    {
        load_image1() ;
        enlarge() ;
        save_image2()  ;

    }


    else if (order== '9')
    {
        load_image1() ;
        shrink() ;
        save_image2() ;
    }

    else if (order == 'a')
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
      load_image1();
      left_mirror();
      save_image2();
    }
    else if (choice ==2)
    {
      load_image1();
      right_mirror();
      save_image2();
    }
        else if (choice ==3)
    {
      load_image1();
      upper_mirror();
      save_image2();
    }
          else if (choice ==4)
         {
           load_image1();
           down_mirror();
           save_image2();
         }
    }

    else if (order == 'b')
    {
        load_image1();
        ShuffleImage() ;
        save_image2();
    }

    else if (order == 'c')
    {
        load_image1() ;
        blure_image() ;
        save_image2() ;
    }


    else if (order == '0' )
    {
        break ;
    }
}

}

void load_image1()
{
    char filename1[100] ;
    cout << "Please Enter Your File Name: " ;
    cin >> filename1 ;
    strcat (filename1 , ".bmp") ;
    readRGBBMP(filename1,image) ;
}

void load_image2()
{
    char filename1[100] ;
    cout << "Please Enter Your File Name: " ;
    cin >> filename1 ;
    strcat (filename1 , ".bmp") ;
    readRGBBMP(filename1,image1) ;
}

void save_image2()
{
    char new_file[100];
    cout << "Enter the new file name: ";
    cin >> new_file;


   strcat (new_file, ".bmp");
   writeRGBBMP(new_file, image1);
}


void flibing_vertically()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            for (int m = 0 ; m < RGB ; m ++ )
            {
                 image1[i][j][m] = image[SIZE-i][j][m]  ;
            }
        }
    }
}

void flibing_horizontally()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            for (int m = 0 ; m < RGB ; m ++ )
            {
                 image1[i][j][m] = image[i][SIZE-j][m]  ;
            }
        }
    }

}

void gray_image()
{
    // in this function we get gray colour image by calculiting the avg value of each three bixels .
    int avg = 0 ;
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
            for (int m = 0 ; m < RGB ; m++)
            {

                    image1[i][j][m] = (image[i][j][1] + image[i][j][2] + image[i][j][3]) / 3 ;

            }
        }


    }
}



void Black_White()
{

    // in this function we get black and white by using gray_image() function
  gray_image() ;

  for (int i = 0 ; i < SIZE ; i ++)
  {
    for (int j = 0 ; j < SIZE ; j ++)
    {
      for (int m = 0 ; m < RGB ; m ++)
      {
        if (image[i][j][m] > 127)
            {
                image[i][j][m] = 255 ;
            }
            else
            {
                image[i][j][m] = 0 ;
            }
      }
    }
  }
}


void shrink()
{
    int m = 0 , n = 0 ;
    int shrink_value  , new_size ;

    cout << "enter shrinking value: " ;
    cin >> shrink_value ;

    new_size = SIZE /shrink_value ;
    for (int i = 0; i < new_size ; i ++)
    {

        for (int j = 0 ; j < new_size ; j ++)
        {

                image1[i][j][RGB-2] = image[m][n][RGB-2] ;
                image1[i][j][RGB-1] = image[m][n][RGB-1] ;
                image1[i][j][RGB] = image[m][n][RGB] ;
                n = n + shrink_value ;


        }
        n = 0 ;
        m = m + shrink_value ;



    }

}


void invert_image()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j ++)
        {
          for (int m = 0 ; m < RGB ; m ++)
          {


            if (image[i][j][m] == 255)
            {
                image1[i][j][m] = 0 ;
            }
            else if (image[i][j][m] == 0 )
            {
                image1[i][j][m] = 255 ;
            }
            else
            {
                image1[i][j][m] = 255 - image[i][j][m];
            }
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
           for (int m = 0 ; m < RGB ; m ++)
           {
               image1[i][j][m] = (image[i][j][m]+image1[i][j][m]) / 2 ;
           }

       }
   }
}

void blure_image()
{
    for (int i = 0 ; i < SIZE ; i ++)
    {
        for (int j = 0 ; j < SIZE ; j++)
        {
            for (int m =0 ; m < RGB ; m ++)
            {

           image1[i][j][m] = (image[i][j][m] + image[i+1][j][m] + image[i][j+1][m] + image[i+1][j+1][m] + image[i-1][j][m] + image[i][j-1][m] + image[i-1][j-1][m] + image[i+2][j][m] + image[i][j+2][m] + image[i+2][j+2][m] + image[i-2][j][m] + image[i][j-2][m] + image[i-2][j-2][m] + image[i+3][j][m] + image[i][j+3][m] + image[i+3][j+3][m] + image[i-3][j][m] + image[i][j-3][m] + image[i-3][j-3][m]) / 19;
            }

        }
    }
}
void darkenImage()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {
        for (int m =0 ; m < RGB ; m ++)
        {

        image1[i][j][m] =image[i][j][m]/2 ;

        }


    }
  }
}
void lightenImage ()
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j< SIZE; j++)
    {
        for (int m =0 ; m < RGB ; m ++)
        {
            image1[i][j][m] =(image[i][j][m]+255)/2;

        }



    }
  }
}
void rotate_90degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           for (int m =0 ; m < RGB ; m ++)
           {
               image1[i][j][m] = image[j][SIZE-i][m]  ;

           }


       }
   }

}
void rotate_180degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           for (int m =0 ; m < RGB ; m ++)
           {
               image1[i][j][m] =image[SIZE-i-1][SIZE-j-1][m] ;

           }



       }
   }

}
void rotate_270degrees()
{
    for (int i = 0 ; i < SIZE ; i ++)
   {
       for (int j = 0 ; j < SIZE ; j ++)
       {
           for (int m =0 ; m < RGB ; m ++)
           {
               image1[i][j][m]=image[SIZE-j][i][m];

           }




       }
   }

}
void left_mirror()
{
  for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[i][j][m];

                }

            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[i][255 - j][m];

                }

            }
        }


}

void right_mirror()
{
    for (int i = 0; i < SIZE; i++) {
            for (int j = SIZE / 2; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[i][j][m];

                }

            }
        }
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE / 2; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[i][255 - j][m];

                }

            }
        }
}
void upper_mirror()
{
  for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                image1[i][j][m] = image[i][j][m];

                }
            }
        }
        for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[255 - i][j][m];

                }

            }
        }
}
void down_mirror()
{
  for (int i = SIZE / 2; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1 [i][j][m] = image[i][j][m];

                }

            }
        }
        for (int i = 0; i < SIZE / 2; i++) {
            for (int j = 0; j < SIZE; j++) {
                for (int m =0 ; m < RGB ; m ++)
                {
                    image1[i][j][m] = image[255 - i][j][m];

                }

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
      for (int m = 0 ; m < RGB ; m ++)
      {
         if (image[i][j][m] == image[i][j+1][m])
            {
                image[i][j][m] = 255 ;
            }
            else
            {
                image[i][j][m] = 0 ;
            }
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
          for (int n = 0 ; n < RGB ; n ++)
          {
         image1[i][j][n] = image[i/2][j/2][n] ;

          }
      }


    }
  }

  else if (chioce == 3 )
  {
    for (int i = 0 ; i < SIZE; i ++)
    {
      for (int j = 0 ; j < SIZE ; j ++)
      {
          for (int n = 0 ; n < RGB ; n ++)
          {
         image1[i][j][n] = image[(i/2)+127][j/2][n] ;

          }
      }

    }
  }

  else if (chioce == 2)
  {
    for (int i = 0 ; i < SIZE ; i ++)
    {
      for (int j = 128 ; j < SIZE ; j ++)
      {
          for (int n = 0 ; n < RGB ; n ++)
          {
         image1[i][j][n] = image[i/2][(j/2)+127][n] ;

          }
      }

    }
  }

  else if (chioce == 4 )
  {
    for (int i = 0 ; i < SIZE ; i ++)
    {
      for (int j = 0 ; j < SIZE ; j ++)
      {
          for ( int n = 0 ; n < RGB ; n ++)
          {
         image1[i][j][n] = image[(i/2)+127][(j/2)+127][n] ;

          }
      }

    }
  }


}

void ShuffleImage() {
   bool check=true;
   int q1,q2,q3,q4;
  cout<<"Please enter the order of quarters you want: ";
  cin>>q1;
  if(q1==1){
      for(int i=0;i<127;i++){
          for(int j=0;j<127;j++){
              for (int m = 0 ; m < RGB ; m ++)
              {
              image1[i][j][m] = image[i][j][m];
              }
          }
      }
  }
   else if(q1==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i][j-127][m] = image[i][j][m];
              }
            }
        }
    }

  else if(q1==3){
      for(int r=127;r<SIZE;r++){
          for(int j=0;j<127;j++){
               for (int m = 0 ; m < RGB ; m ++)
              {
              image1[r-127][j][m] = image[r][j][m];
              }
          }
      }
  }
  else if(q1==4){
      for(int r=127;r<SIZE;r++){
          for(int j=127;j<SIZE;j++){
               for (int m = 0 ; m < RGB ; m ++)
              {
              image1[r-127][j-127][m] = image[r][j][m];
              }
          }
      }
  }

    cin>>q2;
    if(q2==1){
        for(int r=0;r<127;r++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[r][j+127][m] = image[r][j][m];
              }
            }
        }
    }
    else if(q2==2){
        for(int r=0;r<127;r++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[r][j][m] = image[r][j][m];
              }
            }
        }
    }

    else if(q2==3){
        for(int r=127;r<SIZE;r++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[r-127][j+127][m] = image[r][j][m];
              }
            }
        }
    }
    else if(q2==4){
        for(int r=127;r<SIZE;r++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[r-127][j][m] = image[r][j][m];
              }
            }
        }
    }
    cin>>q3;
    if(q3==1){
        for(int i=0;i<127;i++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i+127][j][m] = image[i][j][m];
              }
            }
        }
    }
    else if(q3==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i+127][j-127][m] = image[i][j][m];
              }
            }
        }
    }

    else if(q3==3){
        for(int i=127;i<SIZE;i++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i][j][m] = image[i][j][m];
              }
            }
        }
    }
    else if(q3==4){
        for(int i=127;i<SIZE;i++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i][j-127][m] = image[i][j][m];
              }
            }
        }
    }
    cin>>q4;
    if(q4==1){
        for(int i=0;i<127;i++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i+127][j+127][m] = image[i][j][m];
              }
            }
        }
    }
    else if(q4==2){
        for(int i=0;i<127;i++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i+127][j][m] = image[i][j][m];
              }
            }
        }
    }

    else if(q4==3){
        for(int i=127;i<SIZE;i++){
            for(int j=0;j<127;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i][j+127][m] = image[i][j][m];
              }
            }
        }
    }
    else if(q4==4){
        for(int i=127;i<SIZE;i++){
            for(int j=127;j<SIZE;j++){
                 for (int m = 0 ; m < RGB ; m ++)
              {
                image1[i][j][m] = image[i][j][m];
              }
            }
        }
    }
    else {
        cin.clear();
        cin.ignore();
        cout<<"Please enter available quarter "<< endl ;

        ShuffleImage();

    }
}
