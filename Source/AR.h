/*
  ==============================================================================

    AR.h
    Created: 10 Apr 2021 3:03:12pm
    Author:  Zeno  Loesch

  ==============================================================================
*/

#pragma once
//
//  ADRS.h
//
//  Created by Nigel Redmon on 12/18/12.
//  EarLevel Engineering: earlevel.com
//  Copyright 2012 Nigel Redmon
//
//  For a complete explanation of the ADSR envelope generator and code,
//  read the series of articles by the author, starting here:
//  http://www.earlevel.com/main/2013/06/01/envelope-generators/
//
//  License:
//
//  This source code is provided as is, without warranty.
//  You may copy and distribute verbatim copies of this document.
//  You may modify and use this source code to create binary code for your own purposes, free or commercial.
//
//  1.01  2016-01-02  njr   added calcCoef to SetTargetRatio functions that were in the ADSR widget but missing in this code
//  1.02  2017-01-04  njr   in calcCoef, checked for rate 0, to support non-IEEE compliant compilers
//  1.03  2020-04-08  njr   changed float to double; large target ratio and rate resulted in exp returning 1 in calcCoef
//

#ifndef ADRS_h
#define ADRS_h


class AR {
public:
    AR(void);
    ~AR(void);
    double process(void);
    double getOutput(void);
    int getState(void);
    void gate(int on);
    void setAttackRate(double rate);
    void setReleaseRate(double rate);
   
    void setTargetRatioA(double targetRatio);
    void setTargetRatioDR(double targetRatio);
    void reset(void);
 
    enum envState {
        env_idle = 0,
        env_attack,
        env_release
    };
     int state;
protected:
   
    double output;
    double attackRate;
    double releaseRate;
    double attackCoef;
    double releaseCoef;
    double sustainLevel;
    double targetRatioA;
    double targetRatioDR;
    double attackBase;
    double releaseBase;
 
    double calcCoef(double rate, double targetRatio);
};

inline double AR::process(void)
{
   
       
    switch (state) {
        case env_idle:
            break;
        case env_attack:
            output = attackBase + output * attackCoef;
            if (output >= 1.0) {
                output = 1.0;
                state = env_release;
            } break;
        case env_release:
            output = releaseBase + output * releaseCoef;
            if (output <= 0.0) {
                output = 0.0;
                state = env_idle;
           
            
    }
    }
    return output;
}

inline void AR::gate(int gate) {
    if (gate)
        state = env_attack;
    else if (state != env_idle)
        state = env_release;
}

inline int AR::getState() {
    return state;
}

inline void AR::reset() {
    state = env_idle;
    output = 0.0;
}

inline double AR::getOutput() {
    return output;
}

#endif
