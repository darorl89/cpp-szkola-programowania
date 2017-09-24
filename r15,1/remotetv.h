#ifndef REMOTETV_H_INCLUDED
#define REMOTETV_H_INCLUDED

class Remote;

class Tv
{
    int state;
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
public:
    friend class Remote;
    enum {Off,On};
    enum {MinVal, MaxVal = 20};
    enum {Antenna, Cable};
    enum {TV,DVD};
    Tv(int s = Off, int mc = 125) : state(s), volume(5), maxchannel(mc), channel(1), mode(Cable), input(TV) { }
    void onoff();
    bool ison() const;
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode();
    void set_input();
    void settings() const;
    void remote_mode(Remote & r);
};

class Remote
{
    int mode;
public:
    friend class Tv;
    enum {Normal, Interactive};
    Remote(int m = Tv::TV) : mode(m) { }
    bool volup(Tv & t) { return t.volup(); }
    bool voldown(Tv & t) { return t.voldown(); }
    void onoff(Tv & t) { t.onoff(); }
    void chanup(Tv & t) { t.chanup(); }
    void chandown(Tv & t) { t.chandown(); }
    void set_chan(Tv & t, int c) { t.channel = c; }
    void set_mode(Tv & t) { t.set_mode(); }
    void set_input(Tv & t) { t.set_input(); }
    void settings() const;
};

void inline Tv::onoff() { state = (state == On) ? Off : On; }
bool inline Tv::ison() const { return state == On; }
void inline Tv::set_mode() { mode = (mode == Antenna) ? Cable : Antenna; }
void inline Tv::set_input() { input = (input == TV) ? DVD : TV; }
void inline Tv::remote_mode(Remote & r) { if (state == On) r.mode = (r.mode == Remote::Normal) ? Remote::Interactive : Remote::Normal; }
#endif // REMOTETV_H_INCLUDED
