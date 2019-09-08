# Lem_in: 42 Tier2 Algorithm project 
Your ant colony must move from on room to another. How do you do it in the shortest time possible? This project will get you acquainted with graph traversal algorithms: your program will have to intelligently select paths and precise movements used by the ants.

## Project Objectives
The program will receive the data describing the ant farm from the standard output
in the following format:
```
number_of_ants
the_rooms
the_links
```

The ant farm is defined by the following links:
```
5               <= 5 ants from start room need to walk to end room
##start
1 23 3          <= Start room 1
2 16 7          <= The rooms, which are defined by: name coord_x coord_y
#comment        <= All of it is broken by comments, which start with #
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4              <= The links, which are defined by: name1-name2
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5
#another comment
```

Which corresponds to the following representation:
![image of farm](https://github.com/pootitan/lemin/blob/master/example_farm.png)

For more example map, please check out the map under 'farm' directory.

## Getting Started
The first step is to create exectuable file by Makefile.
```
make
```

Run the executable file with ants_farm map file input, several map files include error tests are locate under farms directory.
```
./lem-in < farms/subject-1.map
```


## Result diplay
You must to display your results on the standard output in the following format:
```
number_of_ants          <= Simply display the farm format
the_rooms
the_links
Lx-y Lz-w Lr-o ...      <= ants walk through result by turn
```
x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y,
w, o represents the rooms’ names.<br/>

So the result of subject-1.map should looks like follow, I put <= for explaination:
```
5                           
##start             
1 23 3           
2 16 7        
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5
0-4
0-6
1-3
4-3
5-2
3-5
#another comment
4-2
2-1
7-6
7-2
7-4
6-5

L1-2 L2-3
L1-4 L2-5 L3-2 L4-3 
L1-0 L2-6 L3-4 L4-5 L5-2 
L2-0 L3-0 L4-6 L5-4 
L4-0 L5-0 
turn: 5
```

## Algorithm
