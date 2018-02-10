/* 
 * Represente la couleur d'une case ou d'une piece de l'echiquier
*/

#ifndef _COLOR_H_
#define _COLOR_H_

enum Color {

    // Permet de representer l'absence de pion sur une case 
    colorNone, 

    colorWhite,

    colorBlack 

};

#endif

/* Couleur terminal */

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */


