:original_name: elb_pro_0019.html

.. _elb_pro_0019:

Quotas and Constraints
======================

You can create dedicated and shared load balancers on ELB console. This section describes the quotas and restrictions that apply to ELB resources.

.. _elb_pro_0019__section9752507451:

ELB Resource Quotas
-------------------

Quotas put limits on the number or amount of resources, such as the maximum number of ECSs or EVS disks that you can create.

:ref:`Table 1 <elb_pro_0019__table834515142196>` lists the default quotas of ELB resources. You can view your quotas by referring to :ref:`Quotas <elb_ug_pe_0000>`.

If the existing resource quota cannot meet your service requirements, you can request an increase to adjust quotas by referring to :ref:`Quotas <elb_ug_pe_0000>`.

.. _elb_pro_0019__table834515142196:

.. table:: **Table 1** ELB resource quotas

   +-----------------------------+------------------------------------------------+---------------+
   | Resource                    | Description                                    | Default Quota |
   +=============================+================================================+===============+
   | Load balancers              | Load balancers per account                     | 50            |
   +-----------------------------+------------------------------------------------+---------------+
   | Listeners                   | Listeners per account                          | 100           |
   +-----------------------------+------------------------------------------------+---------------+
   | Forwarding policies         | Forwarding policies per account                | 500           |
   +-----------------------------+------------------------------------------------+---------------+
   | Backend server groups       | Backend server groups per account              | 500           |
   +-----------------------------+------------------------------------------------+---------------+
   | Certificates                | Certificates per account                       | 120           |
   +-----------------------------+------------------------------------------------+---------------+
   | Backend servers             | Backend servers per account                    | 500           |
   +-----------------------------+------------------------------------------------+---------------+
   | Listeners per load balancer | Listeners that can be added to a load balancer | 50            |
   +-----------------------------+------------------------------------------------+---------------+

.. note::

   The quotas apply to a single account.

Other Quotas
------------

In addition to quotas described in :ref:`ELB Resource Quotas <elb_pro_0019__section9752507451>`, some other resources that you can use are also limited.

You can call APIs to query quotas of the resources described in :ref:`Table 2 <elb_pro_0019__table1912621162511>` by referring to the "Querying Quotas" section in *Elastic Load Balance API Reference*.

.. _elb_pro_0019__table1912621162511:

.. table:: **Table 2** Other quotas

   +------------------------------------------+-------------------------------------------------------------+---------------+
   | Resource                                 | Description                                                 | Default Quota |
   +==========================================+=============================================================+===============+
   | Forwarding rules per forwarding policy   | Forwarding rules that can be added to a forwarding policy   | 10            |
   +------------------------------------------+-------------------------------------------------------------+---------------+
   | Backend servers per backend server group | Backend servers that can be added to a backend server group | 500           |
   +------------------------------------------+-------------------------------------------------------------+---------------+
   | IP address groups per load balancer      | IP address groups per account                               | 50            |
   +------------------------------------------+-------------------------------------------------------------+---------------+
   | Listeners per IP address group           | Listeners that can be associated with an IP address group   | 50            |
   +------------------------------------------+-------------------------------------------------------------+---------------+
   | IP addresses per IP address group        | IP addresses that can be added to an IP address group       | 300           |
   +------------------------------------------+-------------------------------------------------------------+---------------+

Load Balancer
-------------

-  Before creating a load balancer, you must plan its region, type, protocol, and backend servers. For details, see :ref:`Preparations for Creating a Load Balancer <elb_ug_fz_0004>`.
-  The size of files that a load balancer can forward:

   -  Layer 4 listeners: any
   -  Layer 7 listeners: 10 GB or smaller

Listener
--------

-  The listener of a dedicated load balancer can be associated with a maximum of 50 backend server groups.
-  An HTTPS listener can have up to 30 SNI certificates.
-  Once set, the frontend protocol and port of the listener cannot be modified.

Forwarding Policy
-----------------

-  Forwarding policies can be configured only for HTTP and HTTPS listeners.
-  Forwarding policies must be unique.
-  A maximum of 100 forwarding policies can be configured for a listener. If the number of forwarding policies exceeds the quota, the excess forwarding policies will not be applied.
-  Forwarding conditions:

   -  If the advanced forwarding policy is not enabled, each forwarding rule has only one forwarding condition.
   -  If the advanced forwarding policy is enabled, each forwarding rule has up to 10 forwarding conditions.

.. table:: **Table 3** Restrictions on forwarding policies

   +--------------------+---------------------+----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------+
   | Load Balancer Type | Advanced Forwarding | Forwarding Rule                                                                  | Action                                                                                                                                        |
   +====================+=====================+==================================================================================+===============================================================================================================================================+
   | Shared             | Not supported       | Domain name and URL                                                              | **Forward to another backend server group** and **Redirect to another listener**                                                              |
   +--------------------+---------------------+----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------+
   | Dedicated          | Disabled            | Domain name and URL                                                              | **Forward to another backend server group** and **Redirect to another listener**                                                              |
   +--------------------+---------------------+----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------+
   |                    | Enabled             | Domain name, URL, HTTP request method, HTTP header, query string, and CIDR block | **Forward to a backend server group**, **Redirect to another listener**, **Redirect to another URL**, and **Return a specific response body** |
   +--------------------+---------------------+----------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------------------------------+

Backend Server Group
--------------------

The backend protocol of the backend server group must match the frontend protocol of the listener as described in :ref:`Table 4 <elb_pro_0019__table41881780511>`.

.. _elb_pro_0019__table41881780511:

.. table:: **Table 4** The frontend and backend protocols

   +-----------------------------------+-----------------------------------+
   | Frontend Protocol                 | Backend Protocol                  |
   +===================================+===================================+
   | TCP                               | TCP                               |
   +-----------------------------------+-----------------------------------+
   | UDP                               | -  UDP                            |
   |                                   | -  QUIC                           |
   +-----------------------------------+-----------------------------------+
   | HTTP                              | HTTP                              |
   +-----------------------------------+-----------------------------------+
   | HTTPS                             | -  HTTP                           |
   |                                   | -  HTTPS                          |
   +-----------------------------------+-----------------------------------+

Backend Server
--------------

If **Transfer Client IP Address** is enabled, a server cannot serve as both a backend server and a client.

TLS Security Policy
-------------------

You can create a maximum of 50 TLS security policies.
