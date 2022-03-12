# HIGH LEVEL
| ID |           Description             |         Input          |         Expected Output          | Actual Output                 |
|----|-----------------------------------|------------------------|----------------------------------|-----------------------|
| 01 |           Print lock              |Press Button one time   |    Print lock                     |  Print lock                   |
| 02 |          Print unlock             |Press Button two times  |   Print unlock                    | Print unlock                 |
| 03 |Print alarm activation/deactivation|Press Button three times|Print alarm activation/deactivation|Print alarm activation/deactivation|
| 04 |     	Print approach light         |Press Button four times |	     Print approach light         |	Print approach light         |
## Low Level
| ID |              Description                |         Input          |          Expected Output          | Actual Output                  |
|----|-----------------------------------------|------------------------|-----------------------------------|-------------------------------|
| 01 |     Check Print lock                    |Press Button one time   |    All led on                     |  All led on                         |
| 02 |     Check Print unlock                  |Press Button two times  |       All led off                 |  All led off                        |
| 03 |Check Print alarm activation/deactivation|Press Button three times|   All led on in clockwise manner  |All led on clock wise     |
| 04 |    Check Print approach light           |Press Button four times |All led on in anti-clockwise manner|All led off anti clock wise |