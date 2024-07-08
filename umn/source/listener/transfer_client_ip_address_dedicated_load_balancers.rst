:original_name: en-us_topic_0000001794660385.html

.. _en-us_topic_0000001794660385:

Transfer Client IP Address (Dedicated Load Balancers)
=====================================================

Transfer Client IP Address
--------------------------

If you enable **Transfer Client IP Address**, your load balancer will use the IP address of the client to access the backend server.

:ref:`Table 1 <en-us_topic_0000001794660385__table167041254114314>` lists whether you can enable or disable the transfer client IP address function.

.. _en-us_topic_0000001794660385__table167041254114314:

.. table:: **Table 1** Transfer client IP address

   +----------------+-------------------------------------+--------------------------------------+
   | Listener Type  | Enabling Transfer Client IP Address | Disabling Transfer Client IP Address |
   +================+=====================================+======================================+
   | TCP and UDP    | Enabled by default                  | x                                    |
   +----------------+-------------------------------------+--------------------------------------+
   | HTTP and HTTPS | Enabled by default                  | x                                    |
   +----------------+-------------------------------------+--------------------------------------+

Constraints
-----------

-  If you enable **Transfer Client IP Address**, a server cannot be used as both the client and the backend server.

   If the client and the backend server are using the same server and the **Transfer Client IP Address** option is enabled, the backend server will think the packet is sent by itself but not from the client and will not return a response packet to the load balancer. As a result, the return traffic will be interrupted.

-  After this function is enabled, unidirectional download or push traffic may be interrupted when backend servers are being migrated. After the backend servers are migrated, retransmit the packets to restore the traffic.

-  If you add IP addresses as backend servers, the source IP addresses of the clients cannot be passed to these servers.

Alternatives for Obtaining the IP Address of the Client
-------------------------------------------------------

You can obtain the IP address of a client in one of the ways listed in :ref:`Table 2 <en-us_topic_0000001794660385__table640304414221>`.

.. _en-us_topic_0000001794660385__table640304414221:

.. table:: **Table 2** Alternatives

   +----------------+---------------------------------------------------------------------+
   | Listener Type  | Alternatives                                                        |
   +================+=====================================================================+
   | TCP and UDP    | N/A                                                                 |
   +----------------+---------------------------------------------------------------------+
   | HTTP and HTTPS | :ref:`Layer 7 Load Balancing <elb_faq_0090__section12598161410315>` |
   +----------------+---------------------------------------------------------------------+
