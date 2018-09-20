#ifndef LIBLLARP_DNSIPTRACKER_HPP
#define LIBLLARP_DNSIPTRACKER_HPP

#include <llarp/net.hpp>
#include <map>
#include <vector>
#include <llarp/service/address.hpp>

// either a request or response?
// neither, it's a result set row
struct dns_pointer
{
  struct sockaddr *hostResult;
  llarp::service::Address b32addr;
};

struct ip_range
{
  uint8_t octet2;
  uint8_t octet3;
  // FIXME: we're not consecutive
  uint8_t left;
  std::map< uint8_t, dns_pointer * > used;
};

struct dns_iptracker
{
  struct privatesInUse interfaces;
  struct privatesInUse used_privates;
  std::vector< ip_range * > used_ten_ips;
  std::vector< ip_range * > used_seven_ips;
  std::vector< ip_range * > used_nine_ips;
};

void
dns_iptracker_init();

bool
dns_iptracker_setup(llarp::Addr tunGatewayIp);

struct dns_pointer *
dns_iptracker_get_free();

#endif
