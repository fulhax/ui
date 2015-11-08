class Vec2 {

    public:
        float angle;
        float x;
        float y;
        Vec2(float x=0, float y=0);
        void Set(float x, float y);
        void up();
        void down();
        void right();
        void left();
};
