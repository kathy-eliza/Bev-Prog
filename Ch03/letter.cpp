#include "std_lib_facilities.h"

int main()
{
	cout<<"Please enter your first name (followed by 'enter'):\n";
	string first_name;
	cin>>first_name;

	cout<<"Hello,"<<first_name<<"!\n";
	cout<<"Enter the name of the person you want to write to!\n";
	cin>>first_name;

	cout<<"Dear "<<first_name<<",\n";
	cout<<"How are you? I am fine. I miss you. How was your summer?\n";
	cout<<"Please enter a friend's name!\n";

	string friend_name;
	cin>>friend_name;
	cout<<"Have you seen "<<friend_name<<" lately?\n";

	char friend_sex = 0;
	cout<<"Enter an 'm' if the friend is a male and an 'f' if the friend is a female!\n";
	cin>>friend_sex;

	if(friend_sex == 'm')
	{
		cout<<"If you see "<<friend_name<<" please ask him to call me.\n";
	}
	if(friend_sex == 'f')
	{
		cout<<"If you see "<<friend_name<<" please ask her to call me.\n";
	}

	int age;
	cout<<"Enter your age!\n";
	cin>>age;
	if(age <= 0 || age >= 110)
    {
        simple_error("you're kidding!\n");
    }
    cout<<"I hear you just had a birthday and you are "<<age<<" years old.\n";


    if(age < 12)
    {
        cout<<"Next year you will be "<<age+1<<".\n";
    }

    if(age == 17)
    {
        cout<<"Next year you will be able to vote.\n";
    }

    if(age > 70)
    {
        cout<<"I hope you are enjoying retirement.\n";
    }

    cout<<"Yours sincerely,\n\n\nEliza";
    return 0;

}
