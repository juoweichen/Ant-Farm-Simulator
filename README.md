# Lem_in: 42 Tier2 Algorithm project 
Your ant colony must move from on room to another. How do you do it in the shortest time possible? This project will get you acquainted with graph traversal algorithms: your program will have to intelligently select paths and precise movements used by the ants.

## Project Objectives
The goal of this project is to find the quickest way to get n ants across the farm. Quickest way means the solution with the least number of lines, respecting the output format requested below.<br/>

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
1 23 3          <= Start room
2 16 7          <= The rooms, which are defined by: name coord_x coord_y
#comment        <= All of it is broken by comments, which start with #
3 16 3
4 16 5
5 9 3
6 1 5
7 4 8
##end
0 9 5            <= End room
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

**Notes:** The rooms’ names won’t necessarily be numbers, and they won’t necessarily be in the right and continuous order. But most importantly, a room will never start with the character L nor the character # <br/>

If there isn’t enough data to process normally you must display ERROR<br/>

For more example map, please check out the map under 'farm' directory.<br/>

## Traversal rules
1. All ants must start from 'Start' room, their distination is 'End' room
2. Each room can only contain one ant at a time. (except at ##start and ##end which can contain as many ants as necessary.)
3. Only display the ants that moved.
4. At each turn you can move each ant only once and through a tube (the room at the receiving end must be empty).

## Getting Started
The first step is to create exectuable file by Makefile.
```
make
```

Run the executable file with ants_farm map file input, several map files include error tests are locate under 'farms' directory.
```
./lem-in < farms/subject-1.map
```

Alternatively, there's a quick_run_subjects.sh to run all the farm. 
```
sh quick_run_subjects.sh
```

Or run quick_run_generator.sh, it's ganna generate some huge map provided by 42 correction sheet.
```
sh quick_run_generator.sh
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

So the result of subject-1.map should looks like follow
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
In result, it tooks 5 turns for 5 ants to walk from start to end.

# Algorithm
The algorithm would be using [Breath First Search(BFS)](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/) to looking for shortest possible path in graph theory. a graph is an abstract data type which consist by nodes and edges. Nodes have been adjenct with other nodes by egdes, same as the farm here.

## Storing map to graph
The farm would be stored as a graph in program before starting the algorithm. I store the graph by using dictionary. Dictionary is form by key and value pair, room's name has been store as a key in string type, and I create a structure call t_room to store the attribute for each room. The struct defined as follow:
```
typedef	struct	s_room
{
	char        *name;
	int         x;
	int         y;
	t_list      *adlist;
	int         ad_num;
	int         is_occupy;
}               t_room;
```
'adlist' means adjacency list, it the one of the major way to represent the graph in program. For more informations about adjacency list check out this [GeeksforGeeks link](https://www.geeksforgeeks.org/graph-and-its-representations/).<br/>

Dictionary illustration:
```
    Key(Room name)      Value(Room's attribute)
    --------------      -----------------------
        2               room 2's attribute: name, coordinate, adjacent rooms, etc.
        5               room 5's attribute
    otherRoom               ...
    SomeOtherRoom           ...
```

## Find the shortest path for each adjacent room with start room
First, adopting BFS to find the shorest path. For instance, we found the shortest path is B in here:
```
        / [A] - [...] - ... \
        / [B] - [...] - ... \
[Start] - [C] - [...] - ... - [End] 
        \ [D] - [...] - ... /
        \ [E] - [...] - ... /
```
I will block the shortest path (start from B in here), and run the BFS to search on next shortest path.
```
        / [A] - [...] - ... \
        / [X] - [X] - .[X]. \
[Start] - [C] - [...] - ... - [End] 
        \ [D] - [...] - ... /
        \ [E] - [...] - ... /
```
Keep on searching till every adjacent room with start has it's path (or no possible path)
```
        / [X] - [X] - .[X]. \
        / [X] - [X] - .[X]. \
[Start] - [X] - [X] - .[X]. - [End] 
        \ [X] - [X] - .[X]. /
        \ [X] - [X] - .[X]. /
```
After this process, we will have a rank of the path start from shortest to longest.
```
    Name:   Distance:
1.  [B]         5
2.  [C]         6
3.  [A]         11
4.  [E]         13
5.  [D]         14
```

## Distributing ants
In order to reduce the traffic jams, we need to distribute reasonable ants flow to each path. The process is, we place an ant to the current shortest path, then we increase the distance of that path by one.
```
    Name:   Distance:       flow:
1.  [B]         6 (5 + 1)     1
2.  [C]         6
3.  [A]         11
4.  [E]         13
5.  [D]         14

    Name:   Distance:       flow:
1.  [B]         7 (6 + 1)     2
2.  [C]         6
3.  [A]         11
4.  [E]         13
5.  [D]         14

    Name:   Distance:       flow:
1.  [B]         7             2
2.  [C]         7 (6 + 1)     1
3.  [A]         11
4.  [E]         13
5.  [D]         14

// Keep on distributing till all ants have it's path...

```
## Sending the ants
Last, we sending the ants according to our optimis distribution.<br/>
Then...We got it!!!
**Note:** There's other optimum solution better then this, but this one is easiest for me and it can pass all map from generator.

Thanks you for bringing those ants home!
![image of happy ants](https://image.shutterstock.com/image-vector/vector-illustrationmant-strawberry-isolated-on-260nw-735913561.jpg)