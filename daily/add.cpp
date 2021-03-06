#include <iostream>

using namespace std;

class Box
{
    private:
        double length;
        double breadth;
        double height;

    public :
        double getvolume(void)
        {
            return length * breadth * height;
        }
        void setlength(double len)
        {    
            length = len;
        }
        void setbreadth(double bre)
        {
            breadth = bre;
        }
        void setheight(double hei)
        {
            height = hei;
        }

        Box operator+ (const Box& b)
        {
            Box box;
            box.length = this->length + b.length;
            box.height = this->height + b.height;
            box.breadth = this->breadth + b.breadth;

            return box;
        }
        Box()
        {}
        ~Box()
        {}
};

int main()
{
    Box box1,box2,box3,box4;
    double volume = 0.0;

    box1.setbreadth(1);
    box1.setheight(1);
    box1.setlength(1);

    box2.setbreadth(2);
    box2.setheight(2);
    box2.setlength(2);

    box3 = box1 + box2;

    box4 = box1 + box2 + box3;

    volume = box4.getvolume();
    cout << "box4 : " << volume << endl;

    return 0;
}