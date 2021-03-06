#ifndef SERVERKARYCORAMC_H
#define SERVERKARYCORAMC_H

#include "ServerORAM.hpp"

#include "config.h"
#include <zmq.hpp>
#include <pthread.h>

class ServerKaryORAMC : public ServerORAM
{
private:
public:
    //specific
    int evict(zmq::socket_t &socket);

    ServerKaryORAMC();
    ServerKaryORAMC(TYPE_INDEX serverNo, int selectedThreads);
    ~ServerKaryORAMC();

    int writeRoot(zmq::socket_t &socket);

    // eviction subroutine

    int readBucket_evict(TYPE_INDEX bucketID, int shareID, zz_p **output_data, zz_p **output_mac);

    int prepareEvictComputation();

    TYPE_INDEX fullEvictPathIdx[2][H + 1];
};

#endif // SERVERCORAM_H
