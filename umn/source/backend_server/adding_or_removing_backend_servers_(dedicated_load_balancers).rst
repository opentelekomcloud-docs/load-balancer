Adding or Removing Backend Servers (Dedicated Load Balancers)
=============================================================

Scenarios
---------

When you use ELB, ensure that at least a healthy backend server is in the backend server group associated with your load balancer. If incoming traffic increases, you need to add more backend servers.

After a backend server is removed, it cannot receive requests from the load balancer. You can add it back to the backend server group when the traffic goes up again.

If the load balancer is associated with an AS group, instances in the AS group are automatically added to the backend server group associated with the load balancer. If instances are removed from the AS group, they will be automatically removed from the backend server group.

Adding Backend Servers
----------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. On the **Backend Server Groups** tab page, click **Add Backend Server** under **Backend Servers**.
#. Perform the following operations based on the type of the backend servers:

   -  Backend servers in the same VPC as the load balancer: In the **Add Backend Server** dialog box, select the subnet where the backend servers reside, select the backend servers to be added, and click **Next**. Set the server weights and backend ports, and click **Finish**.
   -  Cross-VPC backend servers: In the **Add Cross-VPC Backend Server** dialog box, specify the IP addresses, ports, and weights, and click **OK**.

Removing Backend Servers
------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click its name.
#. In the **Basic Information** area, locate the target backend server and click **Remove** in the **Operation** column. To remove multiple backend servers, select the backend servers you want to remove and click **Remove** above the server list.
#. Click **Yes**.

Adding a Backend Server Group
-----------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image5| and select the desired region and project.

#. Hover on |image6| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Under **Backend Server Groups**, click **Add Backend Server Group**.

#. In the **Add Backend Server Group** dialog box, configure the parameters.

   Configure the parameters based on `Table 1 <#elb_ug_hd_0003__table299811529239>`__ and `Table 2 <#elb_ug_hd_0003__table1022053182319>`__.



.. _elb_ug_hd_0003__table299811529239:

.. table:: **Table 1** Parameters for adding a backend server group

   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Parameter                             | Description                           | Example Value                         |
   +=======================================+=======================================+=======================================+
   | Name                                  | Specifies the name of the backend     | server_group-sq4v                     |
   |                                       | server group.                         |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Backend Protocol                      | Specifies the protocol used by        | HTTP                                  |
   |                                       | backend servers to receive requests.  |                                       |
   |                                       |                                       |                                       |
   |                                       | The backend protocol can be TCP, UDP, |                                       |
   |                                       | HTTP, or HTTPS.                       |                                       |
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
   |                                       |    addition to the number of active   |                                       |
   |                                       |    connections established with each  |                                       |
   |                                       |    backend server, each server is     |                                       |
   |                                       |    assigned a weight based on their   |                                       |
   |                                       |    processing capability. Requests    |                                       |
   |                                       |    are routed to the server with the  |                                       |
   |                                       |    lowest connections-to-weight       |                                       |
   |                                       |    ratio.                             |                                       |
   |                                       | -  **Source IP hash**: The source IP  |                                       |
   |                                       |    address of each request is         |                                       |
   |                                       |    calculated using the consistent    |                                       |
   |                                       |    hashing algorithm to obtain a      |                                       |
   |                                       |    unique hashing key, and all        |                                       |
   |                                       |    backend servers are numbered. The  |                                       |
   |                                       |    generated key is used to allocate  |                                       |
   |                                       |    the client to a particular server. |                                       |
   |                                       |    This allows requests from          |                                       |
   |                                       |    different clients to be routed     |                                       |
   |                                       |    based on source IP addresses and   |                                       |
   |                                       |    ensures that a client is directed  |                                       |
   |                                       |    to the same server that it was     |                                       |
   |                                       |    using previously.                  |                                       |
   |                                       |                                       |                                       |
   |                                       | NOTE:                                 |                                       |
   |                                       |                                       |                                       |
   |                                       | -  Choose an appropriate algorithm    |                                       |
   |                                       |    based on your requirements for     |                                       |
   |                                       |    better traffic distribution.       |                                       |
   |                                       | -  For **Weighted round robin** or    |                                       |
   |                                       |    **Weighted least connections**, no |                                       |
   |                                       |    requests will be routed to a       |                                       |
   |                                       |    server with a weight of 0.         |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Sticky Session                        | Specifies whether to enable sticky    | -                                     |
   |                                       | sessions. If you enable sticky        |                                       |
   |                                       | sessions, all requests from a client  |                                       |
   |                                       | are sent to the same backend server.  |                                       |
   |                                       |                                       |                                       |
   |                                       | NOTE:                                 |                                       |
   |                                       | You can enable sticky sessions only   |                                       |
   |                                       | if you select **Weighted round        |                                       |
   |                                       | robin** for **Load Balancing          |                                       |
   |                                       | Algorithm**.                          |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Sticky Session Type                   | After you enable the sticky session   | Load balancer cookie                  |
   |                                       | feature, select a sticky session      |                                       |
   |                                       | type:                                 |                                       |
   |                                       |                                       |                                       |
   |                                       | -  **Source IP address**: The source  |                                       |
   |                                       |    IP address of each request is      |                                       |
   |                                       |    calculated using the consistent    |                                       |
   |                                       |    hashing algorithm to obtain a      |                                       |
   |                                       |    unique hashing key, and all        |                                       |
   |                                       |    backend servers are numbered. The  |                                       |
   |                                       |    system allocates the client to a   |                                       |
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
   | Stickiness Duration (min)             | Specifies the minutes that sticky     | 20                                    |
   |                                       | sessions are maintained. You can      |                                       |
   |                                       | enable sticky sessions only if you    |                                       |
   |                                       | select **Weighted round robin** or    |                                       |
   |                                       | **Weighted least connections** for    |                                       |
   |                                       | **Load Balancing Algorithm**.         |                                       |
   |                                       |                                       |                                       |
   |                                       | -  Stickiness duration at Layer 4:    |                                       |
   |                                       |    **1** to **60**                    |                                       |
   |                                       | -  Stickiness duration at Layer 7:    |                                       |
   |                                       |    **1** to **1440**                  |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Slow Start                            | Specifies whether to enable slow      | -                                     |
   |                                       | start, which is disabled by default.  |                                       |
   |                                       |                                       |                                       |
   |                                       | After you enable slow start, the load |                                       |
   |                                       | balancer linearly increases the       |                                       |
   |                                       | proportion of requests to send to     |                                       |
   |                                       | backend servers in this mode. When    |                                       |
   |                                       | the slow start duration elapses, the  |                                       |
   |                                       | load balancer sends full share of     |                                       |
   |                                       | requests to backend servers and exits |                                       |
   |                                       | the slow start mode. For details, see |                                       |
   |                                       | `Configuring Slow Start (Dedicated    |                                       |
   |                                       | Load                                  |                                       |
   |                                       | Balancers) <elb_ug_hd_0006.html>`__.  |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Slow Start Duration                   | Specifies how long the slow start     | 30                                    |
   |                                       | will last.                            |                                       |
   |                                       |                                       |                                       |
   |                                       | The duration ranges from **30** to    |                                       |
   |                                       | **1200**, in seconds, and the default |                                       |
   |                                       | value is **30**.                      |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Description                           | Provides supplementary information    | -                                     |
   |                                       | about the backend server group.       |                                       |
   |                                       |                                       |                                       |
   |                                       | You can enter a maximum of 255        |                                       |
   |                                       | characters.                           |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+



.. _elb_ug_hd_0003__table1022053182319:

.. table:: **Table 2** Parameters for configuring a health check

   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Parameter                             | Description                           | Example Value                         |
   +=======================================+=======================================+=======================================+
   | Enable Health Check                   | Specifies whether to enable health    | N/A                                   |
   |                                       | checks.                               |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Protocol                              | Specifies the protocol used by the    | HTTP                                  |
   |                                       | load balancer to perform health       |                                       |
   |                                       | checks on backend servers. You can    |                                       |
   |                                       | select either TCP or HTTP. A selected |                                       |
   |                                       | protocol cannot be changed.           |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Domain Name                           | Specifies the domain name that will   | www.elb.com                           |
   |                                       | be used for health checks.            |                                       |
   |                                       |                                       |                                       |
   |                                       | The domain name can contain digits,   |                                       |
   |                                       | letters, hyphens (-), and periods     |                                       |
   |                                       | (.), and must start with a digit or   |                                       |
   |                                       | letter. The field is left blank by    |                                       |
   |                                       | default and is available only when    |                                       |
   |                                       | the health check protocol is HTTP.    |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Port                                  | Specifies the port used by the load   | 80                                    |
   |                                       | balancer to perform health checks on  |                                       |
   |                                       | backend servers. The port number      |                                       |
   |                                       | ranges from 1 to 65535.               |                                       |
   |                                       |                                       |                                       |
   |                                       | NOTE:                                 |                                       |
   |                                       | If you do not specify a health check  |                                       |
   |                                       | port, the backend port will be used   |                                       |
   |                                       | for health checks by default. If you  |                                       |
   |                                       | specify a port, it will be used for   |                                       |
   |                                       | health checks.                        |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Advanced Settings                     |                                       |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Interval (s)                          | Specifies the maximum time between    | 5                                     |
   |                                       | health checks, in seconds.            |                                       |
   |                                       |                                       |                                       |
   |                                       | The interval ranges from **1** to     |                                       |
   |                                       | **50**.                               |                                       |
   +---------------------------------------+---------------------------------------+---------------------------------------+
   | Timeout (s)                           | Specifies the maximum time required   | 3                                     |
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

#. Click **OK**.

Modifying a Backend Server Group
--------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image7| and select the desired region and project.
#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click |image9| on the right of its name.
#. Modify the parameters as needed and click **OK**.

Deleting a Backend Server Group
-------------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image10| and select the desired region and project.
#. Hover on |image11| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Backend Server Groups**, locate the backend server group, and click |image12| on the right of its name.
#. Click **Yes**.

.. |image1| image:: /images/en-us_image_0241356603.png
.. |image2| image:: /images/en-us_image_0000001120894978.png
.. |image3| image:: /images/en-us_image_0241356603.png
.. |image4| image:: /images/en-us_image_0000001120894978.png
.. |image5| image:: /images/en-us_image_0241356603.png
.. |image6| image:: /images/en-us_image_0000001120894978.png
.. |image7| image:: /images/en-us_image_0241356603.png
.. |image8| image:: /images/en-us_image_0000001120894978.png
.. |image9| image:: /images/en-us_image_0000001205955477.png
.. |image10| image:: /images/en-us_image_0241356603.png
.. |image11| image:: /images/en-us_image_0000001120894978.png
.. |image12| image:: /images/en-us_image_0000001206035439.png
