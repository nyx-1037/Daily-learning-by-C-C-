#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class showcoo {
public:
    showcoo() {
        vector<string> colors = { "#000", "#ff0000", "#00ff00", "#0000ff", "#ffff00", "#ff00ff", "#00ffff", "#ffffff" };
        srand(time(0));
        color = colors[rand() % colors.size()];
    }

    string color() {
        return color;
    }

    void rise() {
        var o = firecracker();
        var n = aheight();
        var speed = this->speed;
        var e = expl;
        var s = size;
        var k = n;
        var m = [&](int) {
            o->style->bottom = o->style->bottom + k * speed + "px";
            k -= k * speed;
            if (k < 2) {
                clearInterval(clear);
                e(o, n, s, speed);
            }
            };
        o->innerHTML = "*";
        if (parseInt(o->style->bottom) < n) {
            clear = setInterval(m, 20);
        }
    }

    void expl(Element o, int n, int s, int speed) {
        int R = n / 3;
        int Ri = n / 6;
        int r = 0;
        int ri = 0;
        for (int i = 0; i < s; i++) {
            Element span = document->createElement("span");
            Element p = document->createElement("p");
            span->style->position = "absolute";
            span->style->left = 0;
            span->style->top = 0;
            span->innerHTML = "*";
            p->style->position = "absolute";
            p->style->left = 0;
            p->style->top = 0;
            p->innerHTML = "+";
            o->appendChild(span);
            o->appendChild(p);
        }
        function spr() {
            r += R * speed;
            ri += Ri * speed / 2;
            vector<Element> sp = o->getElementsByTagName("span");
            vector<Element> p = o->getElementsByTagName("p");
            for (int i = 0; i < sp.size(); i++) {
                sp[i]->style->left = r * cos(360 / s * i) + "px";
                sp[i]->style->top = r * sin(360 / s * i) + "px";
                p[i]->style->left = ri * cos(360 / s * i) + "px";
                p[i]->style->top = ri * sin(360 / s * i) + "px";
            }
            R -= R * speed;
            if (R < 2) {
                clearInterval(clearI);
                o->parentNode->removeChild(o);
            }
        }
        var clearI = setInterval(spr, 20);
    }
};

int main() {
    showcoo happyNewYear;
    return 0;
}