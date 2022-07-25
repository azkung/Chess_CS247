#ifndef _OBSERVER_H_
#define _OBSERVER_H_

class Tile;

class Observer {
    public:
        virtual void notify(Tile &) = 0;
        virtual ~Observer();
};

#endif
