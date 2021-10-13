Adding a Listener
=================

Scenarios
---------

After you create a load balancer, add at least one listener to the load balancer. This listener is a process that checks for requests using the protocol and port you configure for connections from clients to the load balancer, and the protocol and port from the load balancer to backend servers.

The listener also defines the health check configuration, based on which the load balancer continually checks the running statuses of backend servers. If a backend server is detected unhealthy, the load balancer routes traffic to these healthy ones. Traffic forwarding to this server resumes once it recovers.

When you add an HTTP listener, ensure that the subnet of the load balancer has sufficient IP addresses. If the IP addresses are insufficient, add multiple subnets on the **Basic Information** page of the load balancer. After you select a subnet, ensure that ACL rules are not configured for this subnet. If rules are configured, request packets may not be allowed.

Adding a Listener to a Dedicated Load Balancer
----------------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**. Configure the parameters based on `Table 1 <#elb_ug_jt_0011__table627865019713>`__, `Table 2 <#elb_ug_jt_0011__table02842501376>`__, and `Table 3 <#elb_ug_jt_0011__table172911502712>`__.
   

.. _elb_ug_jt_0011__table627865019713:

   .. table:: **Table 1** Parameters for configuring a listener

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Parameter                             | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Name                                  | Specifies the listener name.          | listener-pnqy                         |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Frontend Protocol/Port                | Specifies the protocol and port used  | TCP/80                                |
      |                                       | by the load balancer to receive       |                                       |
      |                                       | requests from clients and forward the |                                       |
      |                                       | requests to backend servers.          |                                       |
      |                                       |                                       |                                       |
      |                                       | The port number ranges from 1 to      |                                       |
      |                                       | 65535, and the following protocols    |                                       |
      |                                       | are supported:                        |                                       |
      |                                       |                                       |                                       |
      |                                       | -  HTTP                               |                                       |
      |                                       |                                       |                                       |
      |                                       | -  TCP                                |                                       |
      |                                       | -  HTTPS                              |                                       |
      |                                       | -  UDP                                |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Redirect                              | Redirects requests to an HTTPS        | N/A                                   |
      |                                       | listener when HTTP is used as the     |                                       |
      |                                       | frontend protocol. If you have both   |                                       |
      |                                       | HTTPS and HTTP listeners, you can use |                                       |
      |                                       | this function to redirect the         |                                       |
      |                                       | requests from the HTTP listener to    |                                       |
      |                                       | the HTTPS listener to ensure          |                                       |
      |                                       | security.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | If you create a redirect for an HTTP  |                                       |
      |                                       | listener, the load balancer will      |                                       |
      |                                       | return HTTP 301 Move Permanently to   |                                       |
      |                                       | the clients.                          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Redirected To                         | Specifies the HTTPS listener to which | N/A                                   |
      |                                       | requests are redirected.              |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Server Certificate                    | Specifies the certificate used by the | N/A                                   |
      |                                       | server to authenticate the client     |                                       |
      |                                       | when HTTPS is used as the frontend    |                                       |
      |                                       | protocol.                             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Enable SNI                            | Specifies whether to enable SNI when  | N/A                                   |
      |                                       | HTTPS is used as the frontend         |                                       |
      |                                       | protocol.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | SNI is an extension to TLS and is     |                                       |
      |                                       | used when a server uses multiple      |                                       |
      |                                       | domain names and certificates. This   |                                       |
      |                                       | allows the client to submit the       |                                       |
      |                                       | domain name information while sending |                                       |
      |                                       | an SSL handshake request. After the   |                                       |
      |                                       | load balancer receives the request,   |                                       |
      |                                       | the load balancer queries the         |                                       |
      |                                       | corresponding certificate based on    |                                       |
      |                                       | the domain name and returns it to the |                                       |
      |                                       | client. If no certificate is found,   |                                       |
      |                                       | the load balancer will return a       |                                       |
      |                                       | default certificate.                  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | SNI Certificate                       | Specifies the certificate associated  | N/A                                   |
      |                                       | with the domain name when the         |                                       |
      |                                       | frontend protocol is HTTPS and SNI is |                                       |
      |                                       | enabled.                              |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Advanced Settings                     |                                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Security Policy                       | Specifies the security policy you can | TLS-1-0                               |
      |                                       | use if you select HTTPS as the        |                                       |
      |                                       | frontend protocol. The following      |                                       |
      |                                       | options are available (for details,   |                                       |
      |                                       | see `Security                         |                                       |
      |                                       | Policy <elb_ug_jt_0022.html>`__):     |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **TLS-1-0**                        |                                       |
      |                                       | -  **TLS-1-1**                        |                                       |
      |                                       | -  **TLS-1-2**                        |                                       |
      |                                       | -  **TLS-1-2-Strict**                 |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Mutual Authentication                 | Specifies whether to enable mutual    | N/A                                   |
      |                                       | authentication between the server and |                                       |
      |                                       | client. Both a server certificate and |                                       |
      |                                       | CA certificate are required for       |                                       |
      |                                       | mutual authentication. You can enable |                                       |
      |                                       | this option if you have set           |                                       |
      |                                       | **Frontend Protocol** to **HTTPS**.   |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | CA Certificate                        | Specifies the certificate used by the | N/A                                   |
      |                                       | server to authenticate the client     |                                       |
      |                                       | when HTTPS is used as the frontend    |                                       |
      |                                       | protocol. This parameter is mandatory |                                       |
      |                                       | if you have set **Frontend Protocol** |                                       |
      |                                       | to **HTTPS** and enabled mutual       |                                       |
      |                                       | authentication.                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Obtain Load Balancer EIP              | Specifies whether to pass the load    | N/A                                   |
      |                                       | balancer EIP to backend servers if    |                                       |
      |                                       | you select **HTTPS** or **HTTP** for  |                                       |
      |                                       | **Frontend Protocol**.                |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Description                           | Provides supplementary information    | N/A                                   |
      |                                       | about the listener.                   |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Tag                                   | Adds tags to the listener. Each tag   | 11/11                                 |
      |                                       | is a key-value pair, and the tag key  |                                       |
      |                                       | is unique.                            |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

   

.. _elb_ug_jt_0011__table02842501376:

   .. table:: **Table 2** Parameters for adding a backend server group

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Parameter                             | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Backend Server Group                  | Specifies a group of servers with the | Create new                            |
      |                                       | same features to receive requests     |                                       |
      |                                       | from the load balancer. Two options   |                                       |
      |                                       | are available:                        |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Create new**                     |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Use existing**\ NOTE:            |                                       |
      |                                       |                                       |                                       |
      |                                       |    To associate an existing backend   |                                       |
      |                                       |    server group, ensure that it is    |                                       |
      |                                       |    not in use. Select the backend     |                                       |
      |                                       |    server group with the correct      |                                       |
      |                                       |    protocol. For example, if the      |                                       |
      |                                       |    frontend protocol is TCP, the      |                                       |
      |                                       |    backend protocol can only be TCP.  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Name                                  | Specifies the name of the backend     | server_group-sq4v                     |
      |                                       | server group.                         |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Backend Protocol                      | Specifies the protocol used by        | HTTP                                  |
      |                                       | backend servers to receive requests.  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Load Balancing Algorithm              | Specifies the algorithm used by the   | Weighted round robin                  |
      |                                       | load balancer to distribute traffic.  |                                       |
      |                                       | The following options are available:  |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Weighted round robin**: Requests |                                       |
      |                                       |    are routed to different servers    |                                       |
      |                                       |    based on their weights, which      |                                       |
      |                                       |    indicate server processing         |                                       |
      |                                       |    performance. Backend servers with  |                                       |
      |                                       |    higher weights receive             |                                       |
      |                                       |    proportionately more requests,     |                                       |
      |                                       |    whereas equal-weighted servers     |                                       |
      |                                       |    receive the same number of         |                                       |
      |                                       |    requests.                          |                                       |
      |                                       | -  **Weighted least connections**: In |                                       |
      |                                       |    addition to the weight assigned to |                                       |
      |                                       |    each server, the number of         |                                       |
      |                                       |    connections processed by each      |                                       |
      |                                       |    backend server is also considered. |                                       |
      |                                       |    Requests are routed to the server  |                                       |
      |                                       |    with the lowest                    |                                       |
      |                                       |    connections-to-weight ratio.       |                                       |
      |                                       | -  **Source IP hash**: The source IP  |                                       |
      |                                       |    address of the request is input    |                                       |
      |                                       |    into a hash algorithm, and the     |                                       |
      |                                       |    resulting hash is used to identify |                                       |
      |                                       |    a server in the static fragment    |                                       |
      |                                       |    table.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | Choose an appropriate algorithm based |                                       |
      |                                       | on your requirements for better       |                                       |
      |                                       | traffic distribution.                 |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Sticky Session                        | Specifies whether to enable sticky    | N/A                                   |
      |                                       | sessions. If you enable sticky        |                                       |
      |                                       | sessions, all requests from a client  |                                       |
      |                                       | during one session are sent to the    |                                       |
      |                                       | same backend server.                  |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | For HTTP and HTTPS listeners,         |                                       |
      |                                       | enabling or disabling sticky sessions |                                       |
      |                                       | may cause few seconds of service      |                                       |
      |                                       | interruption.                         |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Sticky Session Type                   | After you enable the sticky session   | Source IP address                     |
      |                                       | feature, select a sticky session      |                                       |
      |                                       | type:                                 |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Source IP address**: The source  |                                       |
      |                                       |    IP address of each request is      |                                       |
      |                                       |    calculated using the consistent    |                                       |
      |                                       |    hashing algorithm to obtain a      |                                       |
      |                                       |    unique hash key, and all backend   |                                       |
      |                                       |    servers are numbered. The system   |                                       |
      |                                       |    allocates the client to a          |                                       |
      |                                       |    particular server based on the     |                                       |
      |                                       |    generated key. This enables        |                                       |
      |                                       |    requests from different clients to |                                       |
      |                                       |    be routed and ensures that a       |                                       |
      |                                       |    client is directed to the same     |                                       |
      |                                       |    server that it was using           |                                       |
      |                                       |    previously.                        |                                       |
      |                                       | -  **Load balancer cookie**: The load |                                       |
      |                                       |    balancer generates a cookie after  |                                       |
      |                                       |    receiving a request from the       |                                       |
      |                                       |    client. All subsequent requests    |                                       |
      |                                       |    with the same cookie are then      |                                       |
      |                                       |    routed to the same backend server. |                                       |
      |                                       | -  **Application cookie**: The        |                                       |
      |                                       |    application deployed on the        |                                       |
      |                                       |    backend server generates a cookie  |                                       |
      |                                       |    after receiving the first request  |                                       |
      |                                       |    from the client. All requests with |                                       |
      |                                       |    the same cookie generated by       |                                       |
      |                                       |    backend application are then       |                                       |
      |                                       |    routed to the same backend server. |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | Choose an appropriate sticky session  |                                       |
      |                                       | type to better distribute requests    |                                       |
      |                                       | and improve load balancing.           |                                       |
      |                                       |                                       |                                       |
      |                                       | -  Sticky sessions at Layer 4 (for    |                                       |
      |                                       |    TCP or UDP listeners): only        |                                       |
      |                                       |    **Source IP address**              |                                       |
      |                                       | -  Sticky sessions at Layer 7 (for    |                                       |
      |                                       |    HTTP or HTTPS listeners): **Load   |                                       |
      |                                       |    balancer cookie** and              |                                       |
      |                                       |    **Application cookie**             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Cookie Name                           | Specifies the cookie name. If you     | cookieName-qsps                       |
      |                                       | select **Application cookie**, enter  |                                       |
      |                                       | a cookie name.                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Stickiness Duration (min)             | Specifies the minutes that sticky     | 20                                    |
      |                                       | sessions are maintained.              |                                       |
      |                                       |                                       |                                       |
      |                                       | -  Stickiness duration at Layer 4:    |                                       |
      |                                       |    **1** to **60**                    |                                       |
      |                                       | -  Stickiness duration at Layer 7:    |                                       |
      |                                       |    **1** to **1440**                  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Description                           | Provides supplementary information    | N/A                                   |
      |                                       | about the backend server group.       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

   

.. _elb_ug_jt_0011__table172911502712:

   .. table:: **Table 3** Parameters for configuring a health check

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Parameter                             | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Enable Health Check                   | Specifies whether to enable health    | N/A                                   |
      |                                       | checks.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Protocol                              | -  Specifies the protocol used by the | HTTP                                  |
      |                                       |    load balancer to perform health    |                                       |
      |                                       |    checks on backend servers. You can |                                       |
      |                                       |    select either TCP or HTTP. A       |                                       |
      |                                       |    selected protocol cannot be        |                                       |
      |                                       |    changed.                           |                                       |
      |                                       | -  If the frontend protocol is UDP,   |                                       |
      |                                       |    the health check protocol is UDP   |                                       |
      |                                       |    by default.                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Domain Name                           | Specifies the domain name that will   | www.elb.com                           |
      |                                       | be used for health checks. The domain |                                       |
      |                                       | name can contain digits, letters,     |                                       |
      |                                       | hyphens (-), and periods (.), and     |                                       |
      |                                       | must start with a digit or letter.    |                                       |
      |                                       | This field is left blank by default   |                                       |
      |                                       | and needs to be configured only if    |                                       |
      |                                       | you use HTTP as the health check      |                                       |
      |                                       | protocol.                             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Port                                  | Specifies the port used by the load   | 80                                    |
      |                                       | balancer to perform health checks on  |                                       |
      |                                       | backend servers. The port number      |                                       |
      |                                       | ranges from 1 to 65535.               |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | This parameter is optional. If you do |                                       |
      |                                       | not specify a health check port, a    |                                       |
      |                                       | port of the backend server will be    |                                       |
      |                                       | used for health checks by default. If |                                       |
      |                                       | you specify a port, it will be used   |                                       |
      |                                       | for health checks.                    |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Advanced Settings                     | Provides some advanced features.      | N/A                                   |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Interval (s)                          | Specifies the maximum time between    | 5                                     |
      |                                       | health checks, in seconds.            |                                       |
      |                                       |                                       |                                       |
      |                                       | The interval ranges from **1** to     |                                       |
      |                                       | **50**.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Timeout (s)                           | Specifies the maximum time required   | 10                                    |
      |                                       | for waiting for a response from the   |                                       |
      |                                       | health check, in seconds. The timeout |                                       |
      |                                       | ranges from **1** to **50**.          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Check Path                            | Specifies the destination path for    | /index.html                           |
      |                                       | health checks. Configure this         |                                       |
      |                                       | parameter only if you have set        |                                       |
      |                                       | **Protocol** to **HTTP**. The path    |                                       |
      |                                       | can contain 1 to 80 characters and    |                                       |
      |                                       | must start with a slash (/).          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Maximum Retries                       | Specifies the maximum number of       | 3                                     |
      |                                       | health check retries. The value       |                                       |
      |                                       | ranges from **1** to **10**.          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

6. Click **Finish**.
7. Click **OK**.

Adding a Listener to a Shared Load Balancer
-------------------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Under **Listeners**, click **Add Listener**. Configure the parameters based on `Table 4 <#elb_ug_jt_0011__table1441020925310>`__, `Table 5 <#elb_ug_jt_0011__table6414109125314>`__, and `Table 6 <#elb_ug_jt_0011__table124201898534>`__.
   

.. _elb_ug_jt_0011__table1441020925310:

   .. table:: **Table 4** Parameters for configuring a listener

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | **Parameter**                         | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Name                                  | Specifies the listener name.          | listener-pnqy                         |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Frontend Protocol/Port                | Specifies the protocol and port used  | TCP/80                                |
      |                                       | by the load balancer to receive       |                                       |
      |                                       | requests from clients and forward the |                                       |
      |                                       | requests to backend servers.          |                                       |
      |                                       |                                       |                                       |
      |                                       | The port number ranges from 1 to      |                                       |
      |                                       | 65535, and the following protocols    |                                       |
      |                                       | are supported:                        |                                       |
      |                                       |                                       |                                       |
      |                                       | -  HTTP                               |                                       |
      |                                       |                                       |                                       |
      |                                       | -  TCP                                |                                       |
      |                                       | -  HTTPS                              |                                       |
      |                                       | -  UDP                                |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Redirect                              | Redirects requests to an HTTPS        | N/A                                   |
      |                                       | listener when HTTP is used as the     |                                       |
      |                                       | frontend protocol. If you have both   |                                       |
      |                                       | HTTPS and HTTP listeners, you can use |                                       |
      |                                       | this function to redirect the         |                                       |
      |                                       | requests from the HTTP listener to    |                                       |
      |                                       | the HTTPS listener to ensure          |                                       |
      |                                       | security.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | If you create a redirect for an HTTP  |                                       |
      |                                       | listener, the load balancer will      |                                       |
      |                                       | return HTTP 301 Move Permanently to   |                                       |
      |                                       | the clients.                          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Redirected To                         | Specifies the HTTPS listener to which | N/A                                   |
      |                                       | requests are redirected.              |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Server Certificate                    | Specifies the certificate used by the | N/A                                   |
      |                                       | server to authenticate the client     |                                       |
      |                                       | when HTTPS is used as the frontend    |                                       |
      |                                       | protocol.                             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Enable SNI                            | Specifies whether to enable SNI when  | N/A                                   |
      |                                       | HTTPS is used as the frontend         |                                       |
      |                                       | protocol.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | SNI is an extension to TLS and is     |                                       |
      |                                       | used when a server uses multiple      |                                       |
      |                                       | domain names and certificates. This   |                                       |
      |                                       | allows the client to submit the       |                                       |
      |                                       | domain name information while sending |                                       |
      |                                       | an SSL handshake request. After the   |                                       |
      |                                       | load balancer receives the request,   |                                       |
      |                                       | the load balancer queries the         |                                       |
      |                                       | corresponding certificate based on    |                                       |
      |                                       | the domain name and returns it to the |                                       |
      |                                       | client. If no certificate is found,   |                                       |
      |                                       | the load balancer will return a       |                                       |
      |                                       | default certificate.                  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | SNI Certificate                       | Specifies the certificate associated  | N/A                                   |
      |                                       | with the domain name when the         |                                       |
      |                                       | frontend protocol is HTTPS and SNI is |                                       |
      |                                       | enabled.                              |                                       |
      |                                       |                                       |                                       |
      |                                       | Select an existing certificate or     |                                       |
      |                                       | create one.                           |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Advanced Settings                     |                                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Security Policy                       | Specifies the security policy you can | TLS-1-0                               |
      |                                       | use if you select HTTPS as the        |                                       |
      |                                       | frontend protocol. The following      |                                       |
      |                                       | options are available (for details,   |                                       |
      |                                       | see `Security                         |                                       |
      |                                       | Policy <elb_ug_jt_0022.html>`__):     |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **TLS-1-0**                        |                                       |
      |                                       | -  **TLS-1-1**                        |                                       |
      |                                       | -  **TLS-1-2**                        |                                       |
      |                                       | -  **TLS-1-2-Strict**                 |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Idle Timeout                          | Specifies the length of time for a    | -  TCP: The default value is **300**. |
      |                                       | connection to keep alive, in seconds. | -  HTTP or HTTPS: The default value   |
      |                                       | If no request is received within this |    is **60**.                         |
      |                                       | period, the load balancer closes the  |                                       |
      |                                       | connection and establishes a new one  |                                       |
      |                                       | with the client when the next request |                                       |
      |                                       | arrives. This parameter is mandatory  |                                       |
      |                                       | when you have set **Frontend          |                                       |
      |                                       | Protocol** to **TCP**, **HTTP** or    |                                       |
      |                                       | **HTTPS**.                            |                                       |
      |                                       |                                       |                                       |
      |                                       | The idle timeout duration varies      |                                       |
      |                                       | depending on the protocol:            |                                       |
      |                                       |                                       |                                       |
      |                                       | -  TCP: **10** to **4000**            |                                       |
      |                                       | -  HTTP or HTTPS: **0** to **4000**   |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Mutual Authentication                 | Specifies whether to enable mutual    | N/A                                   |
      |                                       | authentication between the server and |                                       |
      |                                       | client. Both a server certificate and |                                       |
      |                                       | CA certificate are required for       |                                       |
      |                                       | mutual authentication. You can enable |                                       |
      |                                       | this option if you have set           |                                       |
      |                                       | **Frontend Protocol** to **HTTPS**.   |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | CA Certificate                        | Specifies the certificate used by the | N/A                                   |
      |                                       | server to authenticate the client     |                                       |
      |                                       | when HTTPS is used as the frontend    |                                       |
      |                                       | protocol. This parameter is mandatory |                                       |
      |                                       | if you have set **Frontend Protocol** |                                       |
      |                                       | to **HTTPS** and enabled mutual       |                                       |
      |                                       | authentication.                       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Description                           | Provides supplementary information    | N/A                                   |
      |                                       | about the listener.                   |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Tag                                   | Adds tags to the listener. Each tag   | 11/11                                 |
      |                                       | is a key-value pair, and the tag key  |                                       |
      |                                       | is unique.                            |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

   

.. _elb_ug_jt_0011__table6414109125314:

   .. table:: **Table 5** Parameters for adding a backend server group

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | **Parameter**                         | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Backend Server Group                  | Specifies a group of servers with the | Create new                            |
      |                                       | same features to receive requests     |                                       |
      |                                       | from the load balancer. Two options   |                                       |
      |                                       | are available:                        |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Create new**                     |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Use existing**\ NOTE:            |                                       |
      |                                       |                                       |                                       |
      |                                       |    To associate an existing backend   |                                       |
      |                                       |    server group, ensure that it is    |                                       |
      |                                       |    not in use. Select the backend     |                                       |
      |                                       |    server group with the correct      |                                       |
      |                                       |    protocol. For example, if the      |                                       |
      |                                       |    frontend protocol is TCP, the      |                                       |
      |                                       |    backend protocol can only be TCP.  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Name                                  | Specifies the name of the backend     | server_group-sq4v                     |
      |                                       | server group.                         |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Backend Protocol                      | Specifies the protocol used by        | HTTP                                  |
      |                                       | backend servers to receive requests.  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Load Balancing Algorithm              | Specifies the algorithm used by the   | Weighted round robin                  |
      |                                       | load balancer to distribute traffic.  |                                       |
      |                                       | The following options are available:  |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Weighted round robin**: Requests |                                       |
      |                                       |    are routed to different servers    |                                       |
      |                                       |    based on their weights, which      |                                       |
      |                                       |    indicate server processing         |                                       |
      |                                       |    performance. Backend servers with  |                                       |
      |                                       |    higher weights receive             |                                       |
      |                                       |    proportionately more requests,     |                                       |
      |                                       |    whereas equal-weighted servers     |                                       |
      |                                       |    receive the same number of         |                                       |
      |                                       |    requests.                          |                                       |
      |                                       | -  **Weighted least connections**: In |                                       |
      |                                       |    addition to the weight assigned to |                                       |
      |                                       |    each server, the number of         |                                       |
      |                                       |    connections processed by each      |                                       |
      |                                       |    backend server is also considered. |                                       |
      |                                       |    Requests are routed to the server  |                                       |
      |                                       |    with the lowest                    |                                       |
      |                                       |    connections-to-weight ratio.       |                                       |
      |                                       | -  **Source IP hash**: The source IP  |                                       |
      |                                       |    address of the request is input    |                                       |
      |                                       |    into a hash algorithm, and the     |                                       |
      |                                       |    resulting hash is used to identify |                                       |
      |                                       |    a server in the static fragment    |                                       |
      |                                       |    table.                             |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | Choose an appropriate algorithm based |                                       |
      |                                       | on your requirements for better       |                                       |
      |                                       | traffic distribution.                 |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Sticky Session                        | Specifies whether to enable sticky    | N/A                                   |
      |                                       | sessions. If you enable sticky        |                                       |
      |                                       | sessions, all requests from a client  |                                       |
      |                                       | during one session are sent to the    |                                       |
      |                                       | same backend server.                  |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | For HTTP and HTTPS listeners,         |                                       |
      |                                       | enabling or disabling sticky sessions |                                       |
      |                                       | may cause few seconds of service      |                                       |
      |                                       | interruption.                         |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Sticky Session Type                   | After you enable the sticky session   | Source IP address                     |
      |                                       | feature, select a sticky session      |                                       |
      |                                       | type:                                 |                                       |
      |                                       |                                       |                                       |
      |                                       | -  **Source IP address**: The source  |                                       |
      |                                       |    IP address of each request is      |                                       |
      |                                       |    calculated using the consistent    |                                       |
      |                                       |    hashing algorithm to obtain a      |                                       |
      |                                       |    unique hash key, and all backend   |                                       |
      |                                       |    servers are numbered. The system   |                                       |
      |                                       |    allocates the client to a          |                                       |
      |                                       |    particular server based on the     |                                       |
      |                                       |    generated key. This enables        |                                       |
      |                                       |    requests from different clients to |                                       |
      |                                       |    be routed and ensures that a       |                                       |
      |                                       |    client is directed to the same     |                                       |
      |                                       |    server that it was using           |                                       |
      |                                       |    previously.                        |                                       |
      |                                       | -  **Load balancer cookie**: The load |                                       |
      |                                       |    balancer generates a cookie after  |                                       |
      |                                       |    receiving a request from the       |                                       |
      |                                       |    client. All subsequent requests    |                                       |
      |                                       |    with the same cookie are then      |                                       |
      |                                       |    routed to the same backend server. |                                       |
      |                                       | -  **Application cookie**: The        |                                       |
      |                                       |    application deployed on the        |                                       |
      |                                       |    backend server generates a cookie  |                                       |
      |                                       |    after receiving the first request  |                                       |
      |                                       |    from the client. All requests with |                                       |
      |                                       |    the same cookie generated by       |                                       |
      |                                       |    backend application are then       |                                       |
      |                                       |    routed to the same backend server. |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | Choose an appropriate sticky session  |                                       |
      |                                       | type to better distribute requests    |                                       |
      |                                       | and improve load balancing.           |                                       |
      |                                       |                                       |                                       |
      |                                       | -  Sticky sessions at Layer 4 (for    |                                       |
      |                                       |    TCP or UDP listeners): only        |                                       |
      |                                       |    **Source IP address**              |                                       |
      |                                       | -  Sticky sessions at Layer 7 (for    |                                       |
      |                                       |    HTTP or HTTPS listeners): **Load   |                                       |
      |                                       |    balancer cookie** and              |                                       |
      |                                       |    **Application cookie**             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Cookie Name                           | Specifies the cookie name. If you     | cookieName-qsps                       |
      |                                       | select **Application cookie**, enter  |                                       |
      |                                       | a cookie name.                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Stickiness Duration (min)             | Specifies the minutes that sticky     | 20                                    |
      |                                       | sessions are maintained.              |                                       |
      |                                       |                                       |                                       |
      |                                       | -  Stickiness duration at Layer 4:    |                                       |
      |                                       |    **1** to **60**                    |                                       |
      |                                       | -  Stickiness duration at Layer 7:    |                                       |
      |                                       |    **1** to **1440**                  |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Description                           | Provides supplementary information    | N/A                                   |
      |                                       | about the backend server group.       |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

   

.. _elb_ug_jt_0011__table124201898534:

   .. table:: **Table 6** Parameters for configuring a health check

      +---------------------------------------+---------------------------------------+---------------------------------------+
      | **Parameter**                         | **Description**                       | **Example Value**                     |
      +=======================================+=======================================+=======================================+
      | Enable Health Check                   | Specifies whether to enable health    | N/A                                   |
      |                                       | checks.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Protocol                              | -  Specifies the protocol used by the | HTTP                                  |
      |                                       |    load balancer to perform health    |                                       |
      |                                       |    checks on backend servers. You can |                                       |
      |                                       |    select either TCP or HTTP. A       |                                       |
      |                                       |    selected protocol cannot be        |                                       |
      |                                       |    changed.                           |                                       |
      |                                       | -  If the frontend protocol is UDP,   |                                       |
      |                                       |    the health check protocol is UDP   |                                       |
      |                                       |    by default.                        |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Domain Name                           | Specifies the domain name that will   | www.elb.com                           |
      |                                       | be used for health checks. The domain |                                       |
      |                                       | name can contain digits, letters,     |                                       |
      |                                       | hyphens (-), and periods (.), and     |                                       |
      |                                       | must start with a digit or letter.    |                                       |
      |                                       | This field is left blank by default   |                                       |
      |                                       | and needs to be configured only if    |                                       |
      |                                       | you use HTTP as the health check      |                                       |
      |                                       | protocol.                             |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Port                                  | Specifies the port used by the load   | 80                                    |
      |                                       | balancer to perform health checks on  |                                       |
      |                                       | backend servers. The port number      |                                       |
      |                                       | ranges from 1 to 65535.               |                                       |
      |                                       |                                       |                                       |
      |                                       | NOTE:                                 |                                       |
      |                                       | This parameter is optional. If you do |                                       |
      |                                       | not specify a health check port, a    |                                       |
      |                                       | port of the backend server will be    |                                       |
      |                                       | used for health checks by default.    |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Advanced Settings                     | Provides some advanced features.      | N/A                                   |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Interval (s)                          | Specifies the maximum time between    | 5                                     |
      |                                       | health checks, in seconds.            |                                       |
      |                                       |                                       |                                       |
      |                                       | The interval ranges from **1** to     |                                       |
      |                                       | **50**.                               |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Timeout (s)                           | Specifies the maximum time required   | 10                                    |
      |                                       | for waiting for a response from the   |                                       |
      |                                       | health check, in seconds. The timeout |                                       |
      |                                       | duration ranges from **1** to **50**. |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Check Path                            | Specifies the destination path for    | /index.html                           |
      |                                       | health checks. Configure this         |                                       |
      |                                       | parameter only if you have set        |                                       |
      |                                       | **Protocol** to **HTTP**. The path    |                                       |
      |                                       | can contain 1 to 80 characters and    |                                       |
      |                                       | must start with a slash (/).          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+
      | Maximum Retries                       | Specifies the maximum number of       | 3                                     |
      |                                       | health check retries. The value       |                                       |
      |                                       | ranges from **1** to **10**.          |                                       |
      +---------------------------------------+---------------------------------------+---------------------------------------+

6. Click **Finish**.
7. Click **OK**.

.. |image1| image:: /images/en-us_image_0241356603.png

.. |image2| image:: /images/en-us_image_0000001120894978.png

.. |image3| image:: /images/en-us_image_0241356603.png

.. |image4| image:: /images/en-us_image_0000001120894978.png

