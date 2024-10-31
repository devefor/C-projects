#include <stdint.h>

#ifndef STRUCT_H  
#define STRUCT_H

// Structure of ETH header - start of Ethernet frame
typedef struct eth_hdr {
    uint8_t mac_dest[6];			// MAC-address destination
	uint8_t mac_src[6];			    // MAC-address source
    uint16_t type;				    // Type of protocol encapsulation (ARP - 0x0806, IP - 0x0800)
} eth_hdr;

// Structure of ARP packet (encapsulation in Ethernet frame)
typedef struct arp_packet {
	uint16_t hw_type;				// Type of Hardware (Ethernet = 1)
	uint16_t proto_type;  		    // Type of protocol (IPv4 = 0x0800)
	uint8_t hw_len;       		    // Length MAC-address (6)
	uint8_t proto_len;    		    // Length of IP-address (4)
	uint16_t operation;             // Operation (ARP-request = 1, ARP-reply = 2)
	uint8_t sender_mac[6];  		// MAC-address sender
	uint8_t sender_ip[4];   		// IP-address sender
	uint8_t target_mac[6];  		// MAC-address target
	uint8_t target_ip[4];   		// IP-address target
} arp_packet;

// Structure of IP header - piece of IP packet (encapsulation in Ethernet frame)
typedef struct ip_hdr {
	uint8_t ver_ihl;				// Version and IP Header Length
	uint8_t tos;					// Type of Service
	uint16_t len;					// Total Length IP (header with Data)
	uint16_t id;					// Identification
	uint16_t flags_offset;		    // Flags and Fragment Offset
	uint8_t ttl;					// Time-to-Live
	uint8_t protocol;				// Type of protocol encapsulation
	uint16_t checksum;			    // Checksum of IP header
	uint8_t ip_src[4];			    // IP-address source
	uint8_t ip_dest[4];			    // IP-address destination
} ip_hdr;

// Structure of ICMP packet - encapsulation in IP packet
typedef struct icmp_packet
{
	
} icmp_packet;

// Structure of UDP header - encapsulation in IP packet
typedef struct udp_hdr
{
	uint16_t port_src;  	        // Port source
	uint16_t port_dest;	            // Port destination
	uint16_t len;			        // Total Length UDP (header with Data)
	uint16_t checksum;	            // IP source + destination, 1 bytes = 0x00,
								    // protocol, Length UDP + UDP header with Data
} udp_hdr;

// Structure of TCP header - encapsulation in IP packet
typedef struct tcp_hdr
{
	
} tcp_hdr;

// Structure of Pseudo header - using for calculate of checksum for IP/UDP/TCP
typedef struct pseudo_hdr
{
	
} pseudo_hdr;

#endif