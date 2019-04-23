# Actor-Actress-Film-Searchable-Database
A program that reads data from a .csv file into a Binary Search Tree, then allows the user to add, delete, and search for records in either database.

The program begins by opening the .csv files and filling 2 Binary Search Trees with the contents of the files. This results in
a BST of actors/actresses sorted initially by name, and a BST of films sorted initially by title.

Then the user is prompted to choose a database to work with, the Actor/Actress tree or the Film tree.

Whichever database is selected, the initial BST has all of its contents moved into a linked list (I would have initially used a
linked list from the start, but the BST was a requirement for the assignmnet). This linked list is used to create new BSTs
for future searches.

The user is then able to add or search for records in whichever database they selected. For the add option, the record is just added 
to the end of the master linked list of records. For the search option, the user is asked for the field by which to search. A BST is 
then created sorted by that field, and the records in the linked list are copied into the new BST. The user is then asked whether to do a 
partial search or complete search. The partial search lists every record that contains the searched value. The complete search only returns 
the record with an exact match. 

If the user runs a complete search and gets a result, they are given the option to either edit the record, remove it, or do nothing.

Once the user run through an option, it brings them back to the menu to select another option, where they can also choose to go back to 
choosing the database to search through.
