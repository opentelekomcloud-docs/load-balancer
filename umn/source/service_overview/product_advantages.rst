:original_name: elb_pro_0005.html

.. _elb_pro_0005:

Product Advantages
==================

Advantages of Dedicated Load Balancers
--------------------------------------

-  Robust performance

   Each dedicated load balancer has exclusive use of isolated resources and can provide guaranteed performance, meeting your requirements for handling a massive number of requests. A single dedicated load balancer deployed in one AZ can handle up to 20 million concurrent connections.

   If you deploy a dedicated load balancer in multiple AZs, its performance such as the number of new connections and the number of concurrent connections will multiply. For example, if you deploy a dedicated load balancer in two AZs, it can handle up to 40 million concurrent connections.

   .. note::

      -  If requests are from the Internet, the load balancer in each AZ you select routes the requests based on source IP addresses.
      -  For requests from a private network:

         -  If clients are in an AZ you select when you create the load balancer, requests are distributed by the load balancer in this AZ. If the load balancer is unavailable, requests are distributed by the load balancer in another AZ you select.
         -  If clients are in an AZ that is not selected when you create the load balancer, requests are distributed by the load balancer in each AZ you select based on source IP addresses.

-  High availability

   Dedicated load balancers can route traffic uninterruptedly. If your servers in one AZ are unhealthy, dedicated load balancers automatically route traffic to healthy servers in other AZs. Dedicated load balancers provide a comprehensive health check system to ensure that incoming traffic is routed only to healthy backend servers, improving the availability of your applications.

-  Ultra security

   Dedicated load balancers support TLS 1.3 and can route HTTPS requests to backend servers. Dedicated load balancers also allow you to select security policies that fit your security requirements.

-  Multiple protocols

   Dedicated load balancers support the following protocols, including TCP, UDP, HTTP, and HTTPS, so that they can route requests from different types of applications.

-  Ease-of-use

   Dedicated load balancers provide a diverse set of algorithms that allow you to configure different traffic routing policies to meet your requirements while keeping deployments simple.

-  High reliability

   Dedicated load balancers can be deployed across AZs and can distribute traffic more evenly.

Advantages of Shared Load Balancers
-----------------------------------

-  Robust performance

   Shared load balancers are deployed in clusters, which can handle up to 100 million concurrent connections and 1 million new connections per second, meeting your requirements for handling huge numbers of concurrent requests.

-  High availability

   Shared load balancers can route traffic across AZs, ensuring that your services are uninterrupted. If servers in an AZ are unhealthy, ELB automatically routes traffic to healthy servers in other AZs. Shared load balancers provide a comprehensive health check mechanism to ensure that incoming traffic is routed to only healthy backend servers, improving the availability of your applications.

-  Multiple protocols

   Shared load balancers support the following protocols: TCP, UDP, HTTP, and HTTPS, so that they can route requests from different types of applications.

-  Ease-of-use

   Shared load balancers provide a diverse set of algorithms that allow you to configure different traffic routing policies to meet your requirements while keeping deployments simple.

-  High reliability

   Shared load balancers can be deployed across AZs and can distribute traffic more evenly.
