//
//  main.cpp
//  Singleton
//
//  Created by le quang vinh on 3/16/19.
//  Copyright © 2019 Vinh Le. All rights reserved.
//

#include <iostream>
#include <string>

class Device{
public:
    virtual void Send(std::string inData) = 0;
    virtual void SetSpeed(long inSpeed) = 0;
    virtual long GetSpeed() = 0;
protected:
private:
};

class Wifi: public Device{
public:
    void Send(std::string inData){
        std::cout << "Send by wifi: " << inData << " Speed: " << m_speed << std::endl;
    }
    void SetSpeed(long inSpeed){
        m_speed = inSpeed;
    }
    long GetSpeed(){
        return m_speed;
    }
    static Device* instance(){
        if(!m_instance){
            m_instance = new Wifi;
        }
        return m_instance;
    }
protected:
    long m_speed;
private:
    static Wifi* m_instance;
    
    Wifi(){
        m_speed = 100;
    }
};

class Bluetooth: public Device{
public:
    void Send(std::string inData){
        std::cout << "Send by bluetooth: " << inData << " Speed: " << m_speed << std::endl;
    }
    void SetSpeed(long inSpeed){
        m_speed = inSpeed;
    }
    long GetSpeed(){
        return m_speed;
    }
    static Device* instance(){
        if(!m_instance){
            m_instance = new Bluetooth;
        }
        return m_instance;
    }
protected:
    long m_speed;
private:
    static Bluetooth* m_instance;
    
    Bluetooth(){
        m_speed = 50;
    }
};

Wifi *Wifi::m_instance = 0;
Bluetooth *Bluetooth::m_instance = 0;

int main(int argc, const char * argv[]) {
    Bluetooth::instance()->SetSpeed(20);
    Bluetooth::instance()->Send("Bluetooth device 1");
    Wifi::instance()->Send("Wifi device 1");
    return 0;
}
