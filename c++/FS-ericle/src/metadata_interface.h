#ifndef __METADATA_INTERFACE_H
#define __METADATA_INTERFACE_H

class metadataInterface
{
public:
    metadataInterface() {}
    virtual ~metadataInterface() {}


private:
    metadataInterface( const metadataInterface& source );
    void operator = ( const metadataInterface& source );
};


#endif // __METADATA_INTERFACE_H
