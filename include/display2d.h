#include <iostream>
#include "board.h"
#include <thread>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Display2D {

    struct Piece2D {

      sf::CircleShape piece;
      sf::Color color;
      float x;
      float y;
      int scale_ ;

      Piece2D(std::tuple<Coordinate, Color> p, int nbCases): scale_{nbCases},  piece(1200 / (nbCases * 2.5)) {
        auto coord = std::get<0>(p);
    
        x = static_cast<float>(coord.getX());
        y = static_cast<float>(coord.getY());
        if (std::get<1>(p) == 1) color = sf::Color::Red;
        else color = sf::Color::Green;
      }
      Piece2D(Coordinate coord, int nbCases): piece( 1200  / (nbCases * 2.5)) , scale_{nbCases} {
        x = static_cast<float>(coord.getX());
        y = static_cast<float>(coord.getY());
        color = sf::Color::Yellow;
      }        


      void displayPiece(std::size_t size) {
        piece.setFillColor(color);
        piece.setOutlineThickness(3);
        piece.setOutlineColor(sf::Color(160,160,160));
        int rectSize = 1200 / size;
        piece.setPosition(sf::Vector2f( ( rectSize * y + 15), ( rectSize * x + 15) ));
      }
    };

    // Taille de la fenêtre 
    std::size_t size_ {1200};
    // SFML window
    sf::RenderWindow window_;
    // Contient les coordonnées et la couleur des pièces
    std::vector<std::tuple<Coordinate, Color>> state_{};
    // Contient les coordonnées des deplacements possibles
    std::vector<Coordinate> help_;
    // Nombre de cases
    int scale_ {};
    // Liste des cases de l'échiquier 
    std::vector<sf::RectangleShape> square;
    // Coordonnées de la souris 
    Coordinate mouse;
    // Liste des pieces de l'échiquier
    std::vector<Piece2D> pieces_;



  public:

    Display2D(int nbCases);
    ~Display2D() = default;

    void render();
    void setState(std::vector<std::tuple<Coordinate, Color>> state) {state_ = state;}
    void setPieceHelp(std::vector<Coordinate> help) {help_ = help;}
    void displayBoard();
    void displayPieces();
    void displayHelp();
    void hideHelp() {help_.clear();}
    Coordinate getMousePosition() {
      auto lastCoord = mouse;
      while (mouse.getX() == lastCoord.getX() && mouse.getY() == lastCoord.getY() ) {

      } 
      return mouse;
    }
    void update();
    void updateHelp();

};