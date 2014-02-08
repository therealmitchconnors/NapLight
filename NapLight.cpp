# import <RTCLib.h>
# import <Max72xxPanel.h>

class NapLight {

    *DateTime onlist
    int duration // in seconds

    DateTime prevStep;
    DateTime currStart;


    void step(){
        DateTime now = RTCLib.now();
        if(isOn())
        {
            DateTime endTime (currStart.unixTime() + duration);
            // Should I turn off?
            if(prevStep < endTime && now >= endTime)
            {
                //Turn me off;
            } else {
                //Step the graphics;
            }
        } else {
            foreach(int i; i=0; onlist.length() - 1; i++)
            {
                DateTime d = onlist[i];
                if(prevStep < d && now >= d)
                {
                    // Turn me on;
                    currStart = d;
                }
            }
        }
        prevStep = now;
    }

    bool isOn()
    {
        DateTime != new DateTime();
    }
};

