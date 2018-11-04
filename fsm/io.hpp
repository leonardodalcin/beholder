#pragma once

class io {
   public:
    io(/*drive*/);
    void write_pin(std::string n);
    void read_pin(std::string n);

    void open(bool op);
    bool is_open();
    bool is_ejected();

   private:
    // _driver
};
