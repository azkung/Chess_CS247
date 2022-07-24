#ifndef TEXT_OBSERVER_H_
#define TEXT_OBSERVER_H_
#include "observer.h"
#include <string>
#include <vector>
#include "tile.h"
#include "piece.h"

class textObserver : public Observer {
        std::vector<std::vector<std::string>> board;

    public:
        textObserver();
        ~textObserver();
        void notify(Tile &subject);
};

#endif // TEXT_OBSERVER_H_