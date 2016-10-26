//
//  prog5.c
//  slone_james_prog1-362
//
//  Created by James Slone on 4/7/16.
//  Copyright © 2016 James Slone. All rights reserved.
//

#include <stdio.h>

int prog5(int argc, const char * argv[]) {
    int a[] = { 100, 99, 97, 95, 90, 87, 86, 83, 81, 77, 74, 69, 63, 50, 44, 43, 39, 31, 29, 12 };
    //int a[] = { 123456, 342100, 87539, 606006, 443322, 198371, 99109, 88018, 707007 };
    int n = sizeof(a) / sizeof(a[0]);
    int temp, location;
    
    for (int i = 1; i<n; i++) {
        temp = a[i];
        location = i - 1;
        while (location >= 0 && a[location] > temp) {
            a[location + 1] = a[location];
            location--;
        }
        a[location + 1] = temp;
    }
    
    for (int e = 0; e < n; e++) {
        printf("%d\n", a[e]);
    }
    return 0;
}