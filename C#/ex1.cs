class BBQ
    {
        public int chicken;
        public int oil;
        public int source;
        public BBQ()
        {
            chicken = 0;
            oil = 0;
            source = 0;
        }
        public BBQ(int chicken, int oil, int source)
        {
            this.chicken = chicken;
            this.oil = oil;
            this.source = source;
        }
        public virtual bool checkStock()
        {
            if(Math.Abs(chicken - source) > 2)
            {
                return false;
            }
            if (Math.Abs(chicken - oil*2) > 2)
            {
                return false;
            }
            return true;
        }
        public void addChicken(int iChicken)
        {
            chicken = iChicken;
        }
        public void addOil(int iOil)
        {
            oil = iOil;
        }
        public void addSource(int iSource)
        {
            source = iSource;
        }
    }