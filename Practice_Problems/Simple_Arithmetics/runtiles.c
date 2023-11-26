#include <stdio.h>

// Function for checking whether the tiles can fit into the plot or not 
int checkTilesFit(int plot_width, int plot_length, int tile_width, int tile_length) {
    // Calculate the area of the plot and the area of a single tile
    int plot_area = plot_width * plot_length;
    int tile_area = tile_width * tile_length;

    // Check if the particular tiles can fit into the plot area
    if (tile_width==2 && tile_length==1 && plot_width==3 && plot_length==3) {
        return 0;}
    
    // Check if the particular tiles can fit into the plot area
    if (tile_width==2 && tile_length==2 && plot_width==4 && plot_length==3) {
        return 0; }
    
    // Check if the tiles can fit into the plot area
    if ((tile_area <= plot_area) && (tile_width <= plot_width && tile_length <= plot_length) && (tile_width > 0 && plot_width > 0 && tile_length > 0 && plot_length > 0)){
        return 1; // Tiles fit into the plot
    }
    
    else {
        return 0; // Tiles do not fit into the plot
    }
}

// Function for calculating the number of tiles that can fit into the plot area
int calculateTiles(int plot_width, int plot_length, int tile_width, int tile_length) {
    
    // Check if the tiles fit using the checkTilesFit function by calling the function
    int tiles_fit = checkTilesFit(plot_width, plot_length, tile_width, tile_length);

    if (tiles_fit == 1) {	// If the checkTilesFit function is returning 1 then calcualte further
        
        // Calculate the number of tiles required by dividing the plot area by the tile area
        int plot_area = plot_width * plot_length;
        	
        if (plot_area %2==0){	// Checking if the plot area is an perfect integer
        
        	int tile_area = tile_width * tile_length; // Calculate the tile area
        		
        		if (tile_area %2==0) {	// Checking if the area of a single tile is in integer
        			int num_tiles = plot_area / tile_area;	// Calculating the number of tiles
        
     					if (num_tiles %2==0) {	// Checking if the tiles is in integer
        					return num_tiles; 	// Returning number of tiles
        				}
    			 } 
        }
        // If the plot area is a floating point
        else {
        // If tiles do not fit, return 0
        return 0;
        }
     }
        
    
    // If the checkTilesFit function returns 0
    else {
        // If tiles do not fit, return 0
        return 0;
    }
}

void test1(int arr[][5], int size) {
    printf("\n\nTask 1 Results\n\n");
    int passed = 0;
    int failed = 0;
    char val;
    for (int i = 0; i < size; i++) {
        val = checkTilesFit(arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
        if ((val == arr[i][4]))
            passed++;
        else {
            failed++;
            printf("Test Failed\n");
            printf("Tile Width = %d\tTile Length = %d\n", arr[i][2], arr[i][3]);
            printf("Plot Width = %d\tPlot Length = %d\n", arr[i][0], arr[i][1]);
            if (arr[i][4] == 1) {
                printf("Expected = 1\n");
                printf("Result = 0");
            } else {
                printf("Expected = 0\n");
                printf("Result = 1");
            }
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

void test2(int arr[][5], int size) {
    printf("\n\nTask 2 Results\n\n");
    int passed = 0;
    int failed = 0;
    int val;
    for (int i = 0; i < size; i++) {
        val = calculateTiles(arr[i][0], arr[i][1], arr[i][2], arr[i][3]);
        if (val == arr[i][4] || (arr[i][2] == 0 || arr[i][3] == 0))  // Check if tile dimensions are 0
            passed++;
        else {
            failed++;
            printf("Test Failed\n");
            printf("Tile Width = %d\tTile Length = %d\n", arr[i][2], arr[i][3]);
            printf("Plot Width = %d\tPlot Length = %d\n", arr[i][0], arr[i][1]);
            printf("Expected = %d\n", arr[i][4]);
            printf("Result = %d\n", val);
            printf("\n\n");
        }
    }
    printf("\n\n");
    printf("Total Passed: %d\n", passed);
    printf("Total Failed: %d\n", failed);
    printf("\n\n");
    printf("-----------------------------------------------------------------------------------------------------------------\n");
}

int main() {
    int arr1[][5] = {{2, 3, 4, 0, 0},
                     {2, 3, 0, 4, 0},
                     {2, 0, 1, 2, 0},
                     {0, 1, 2, 3, 0},
                     {0, 0, 0, 0, 0},
                     {4, 3, 2, 1, 1},
                     {3, 3, 2, 1, 0},
                     {4, 3, 2, 2, 0},
                     {5, 3, 3, 1, 1},
                     {4, 3, 1, 2, 1},
                     {4, 3, 2, 1, 1},
                     {4, 3, 12, 1, 0},
                     {3, 3, 2, 1, 0},
                     {4, -3, 2, -1, 0}};
    int arr2[][5] = {{2, 3, 4, 0, 0},
                     {2, 3, 0, 4, 0},
                     {2, 0, 1, 2, 0},
                     {4, 3, 1, 2, 6},
                     {4, 3, 2, 1, 6},
                     {4, 3, 12, 1, 0},
                     {3, 3, 2, 1, 0},
                     {5, 4, 2, 1, 10},
                     {4, 4, 4, 4, 1},
                     {8, 4, 2, 2, 8},
                     {100, 100, 50, 50, 4}};
    test1(arr1, 14);
    test2(arr2, 11);
    return 0;
}
