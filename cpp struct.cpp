/* 
solve by Sami Zain...
for any help please contact facebook.com/javaworkhosu
*/


#include<iostream> // insert the header file for input and output.
#include<iomanip> // insert the header file for formating...
using namespace std;
void displayheaders(); // declare the function.
void inputcourse(); // declare the function.
void displayer(string a[5],string b[5],string c[5],string d[5]);// declare the function with the 5 string arrays parameters.
struct uni{
	/*
	define a structure with the name uni.....
Structure:
	
A data structure is a group of data elements grouped together under one name. 
These data elements, known as members, can have different types and different lengths.
For example: You want to store some information about a person: his/her name, citizenship number and salary. 
You can easily create different variables name, citNo, salary to store these information separately.
However, in the future, you would want to store information about multiple persons. Now, you'd need to create different variables for each
information per person: name1, citNo1, salary1, name2, citNo2, salary2
You can easily visualize how big and messy the code would look. Also, since no relation between the variables (information) would exist,
it's going to be a daunting task. A better approach will be to have a collection of all related information under a single name Person,
and use it for every person. Now, the code looks much cleaner, readable and efficient as well.
This collection of all related information under a single name Person is a structure
Declaretion of structure:
The struct keyword defines a structure type followed by an identifier (name of the structure).
Then inside the curly braces, you can declare one or more members (declare variables inside curly braces) of that structure. 
	*/
		string course;
		string semesters;
		/*
Here a structure uni is defined which has 2 members: course , semesters.
When a structure is created, no memory is allocated.
The structure definition is only the blueprint for the creating of variables. You can imagine it as a datatype.
		*/
	};
int main(){
	

inputcourse();
	}
void  displayheaders(){ //defination of function...

cout<<"#"<<"    Course code"<<"    course Name"<<setw(25)<<"semester"<<"   Lounching year"<<endl;
cout<<"------------------------------------------------------------------------"<<endl;
}
void inputcourse()
{
	uni name[5]; /*Once you declare a structure person as above. You can define a structure variable as: uni name , uni class etc....
but in this line we declare an Array structure with name uni name[5]; reason is that we want to take information from the user for five time.
by declareing the five structure type variable we declare an array which mean we can store the information 5 times.
When structure variable or Array is defined, only then the required memory is allocated by the compiler. */
	string Ccode[5]; //An string type Array. in this array we will store the course code.
	string Syear[5];  //An string type Array. in this array we will store the Semester year like 2011 , 2012 , 2013 etc....
	string coursename[5];  //An string type Array. in this array we will store the course names...
	string semsfall[5];   // //An string type Array. in this array we will store the Semester years like fall 2012, spring 2013 etc...
	
for (int i=0; i<5; i++) // A loop for taking the input from user for 5 times...
{
cout<<"Enter the name of the course along with course code: ";
getline(cin,name[i].course);
/*
getline()
To get an entire line from cin, there exists a function, called getline,
that takes the stream (cin) as first argument, and the string variable as second.
if we use cin instead of getline then c++ will take input only first word till the blank space and after the blank space all input will lost.
To taking the input as whole line or a long sentence we use the getline() function.

name[i].course:
The members of structure variable is accessed using a dot (.) operator.
Suppose, you want to access course data member of structure then you will use name.course where the name is structure type variable and course is data member.
name[i].course mean we have array so we are using name variable index as i to store the information.

*/
cout<< "Enter Semester: ";
getline(cin,name[i].semesters);	// Access and store the semester information in the semesters data member of structure..

Ccode[i]= name[i].course.substr(0,6);
/*
substr():
This function is very useful to extract the strings from the string variable.
It returns a string copied starting at index pos for n characters or up to the end of the invoking string object, whichever comes first including blank space. 
If only pos is supplied, the function returns the string copied starting at index pos until the end of the invoking string object.
for example we have a string variable name s = "Hello world"; and we want to extract the word hello from it then we will use Substr function as substr(0,5);
Because we know that hello is starting from the 0 position and contains 5 character so the last value is 5.
Ccode[i]= name[i].course.substr(0,6); we know that course code may be consist on 5 or 6 so we give it last position 6 and assign this value to CCode Array.

*/
Syear[i] = name[i].semesters;// Assign the value of semester year to SYear Array. example Fall 2013 , spring 2013 etc...
coursename[i]= name[i].course.substr(6); // here we want to store the course name without course code so we set substr(6) only pos is supplied, the function returns the string copied starting at index pos until the end of the invoking string object. 
semsfall[i]=  name[i].semesters.substr(name[i].semesters.size()-4);	//size() return the size of vectore , string or a variable here we subtract the last 4 characters from the string and assign semsfall array because we know that year containts only 4 characters like 2011, 2012 etc....
}
displayheaders(); // Calling the function
displayer(Ccode,Syear,coursename,semsfall);	// calling the function by passing the arrays..
	
}

void displayer(string a[5],string b[5],string c[5],string d[5])
{
	/*
We know that each subject name length may not be same some names have long length and some short. So the information cannot be print in tabular shape
So we need to make the fixed length for each subject name, and we also know that a subject may not be long then 30 character so in the below portion
So I fixed the length of each subject name. Example a subject name is "Calculus" have 8 character length so I add 22 blank spaces to make it 30 character length name and same proses for each name.

	*/
for(int i= 0;i<5; i++)
{
if(c[i].length()<30) // checking the subject name if its character length is less then 30. Length() function return the length of variable or a string...
{
int n = 30 - c[i].length(); // checking how many blank spaces need to add in the subject name. example a name is "Calculus" 8 lenght so 30-8 = 22; we need 30 blank spaces.
for (int j=0; j<n; j++) // a loop for adding the blank spaces in the name. example we need 22,12 ,2 or 10 blank spaces so this will repete according to the requires.
{
c[i]= c[i]+ " "; // Adding the blank spaces in the subject names. to make equal length of each subject so that we can print them in tabular form.
}

}
cout<<i+1<<"\t"<<a[i]<<"\t"<<c[i]<<"\t"<<b[i]<<"\t"<<d[i]<<endl;
}	
}
