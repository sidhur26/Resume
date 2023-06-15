#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"



student **create_class_list(char *filename, int *sizePtr){
	
	student **class_list;


	/*write your implementation here*/
	int class_size;                              //initializes the class size
	FILE *input_file = fopen(filename, "r");
	fscanf(input_file,"%d", &class_size);        // reads the class size from the file and changes class_size
	*sizePtr = class_size;                       // sizePtr points to the class size

	class_list = malloc(class_size*sizeof(student*));      //allocates memory for an array of pointers
	for(int i=0;i<class_size;i++){
		class_list[i] = calloc((class_size +1),sizeof(student));         //allocates memory for each pointer in the array of pointer and initializes to 0
	}

	for(int i=0;i<class_size;i++){
		fscanf(input_file,"%d",&class_list[i]->student_id);   // adds student id from file into class_list[i]
		fscanf(input_file,"%s",class_list[i]->first_name);    // adds students first name from file into class_list[i]
		fscanf(input_file,"%s",class_list[i]->last_name);     // adds students last name from file into class_list[i]
	}

	fclose(input_file);       //closes the file when done using it




	/* finally return the created class list*/
	return class_list;
}

int find(int idNo, student **list, int size)
{
	
	/*write your implementation here and update the return accordingly*/
	int stud_check = 0;                   //initializes stud_check equal to 0
	for(int i =0;i<size;i++){
		if(list[i]->student_id == idNo){  // checks if there is a student in the list with student_id = idN0
			stud_check = 1;
			return i;                       // returns the index
		}
	}
	if(stud_check==0){        // checks if stud_check was changed
		return -1;            // returns -1 if stud_check remains unchanged
	}
}

void input_grades(char *filename, student **list, int size)
{

	/*write your implementation here*/
	int stud_id;
	int index;
	FILE *input_file = fopen(filename, "r");
	for(int i =0;i<size;i++){
		fscanf(input_file, "%d",&stud_id);            // Adds the first value on the line to the stud_id variable
		index = find(stud_id,list,size);              // Finds the index in list where the student number is
		fscanf(input_file, "%d",&list[index]->project1_grade);   // Adds the second value on the line to the project 1 grade
		fscanf(input_file, "%d",&list[index]->project2_grade);   // Adds the third value on the line to the project 2 grade
	}
	fclose(input_file);     // Closes the file
}

void compute_final_course_grades(student **list, int size)
{
	
	/*write your implementation here*/
	for(int i =0;i<size;i++){
		list[i]->final_grade = (list[i]->project1_grade + list[i]->project2_grade)/2.0;  // Gets the average of project1 grade and project grade and sets the final grade to the average
	}
}

void output_final_course_grades(char *filename, student **list, int size)
{
	
	/*write your implementation here*/
	FILE *input_file = fopen(filename,"w");
	fprintf(input_file,"%d\n",size);                       // Puts the number of students in the first line of the file
	compute_final_course_grades(list,size);
	for(int i =0;i<size;i++){
		fprintf(input_file,"%d ",list[i]->student_id);    // Puts student number into the file on the next line
		fprintf(input_file,"%f\n",list[i]->final_grade);   // Prints final grade into the file after the student number
	}
	fclose(input_file);     // closes the file
}


void withdraw(int idNo, student **list, int* sizePtr)
{
	/*write your implementation here*/
	int i;
	int index = find(idNo, list, *sizePtr);    // Finds index of student withdrawing
	if(index == -1){
		printf("Student is not in the list\n");    // If student was not found in list prints a message
	}
	else{
		for(i=index;i<*sizePtr;i++){
			list[i] = list[i+1];              // Shifts all students between the withdrawing student and last student to the left one position
		}
		free(list[i]);                        // Deallocates the memory for the student withdrawing
		*sizePtr = *sizePtr-1;                // Decreases number of students by one
	}
}

void destroy_list(student **list, int *sizePtr)
{
	/*write your implementation here*/
	for(int i =0;i<*sizePtr;i++){
		free(list[i]);                 // Deallocates memory for each pointer in the array of pointers
	}
	free(list);        // Deallocates memory for the array of pointers
	*sizePtr = 0;      // sets the variable that stores the size to zero;
}
