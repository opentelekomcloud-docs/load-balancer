Sticky Session
==============

Sticky sessions ensure that requests from a client always get routed to the same backend server before a session elapses.

Here is an example that describes what sticky sessions. Assume that you have logged in to a server. After a while, you send another request. If sticky sessions are not enabled, the request may be routed to another server, and you will be asked to log in again. If sticky sessions are enabled, all your requests are processed by the same server, and you do not need to repeatedly log in.

Sticky sessions at Layer 4 are different from those at Layer 7.

Prerequisites
-------------

You have selected **Weighted round robin** for **Load Balancing Algorithm**.

Differences Between Sticky Sessions at Layer 4 and Layer 7
----------------------------------------------------------



.. _elb_ug_jt_0004__table5918161554815:

.. table:: **Table 1** Sticky session comparison

   +-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | OSI Layer             | Listener's Protocol   | Sticky Session Type   | Stickiness Duration   | Scenarios Where       |
   |                       |                       |                       |                       | Sticky Sessions       |
   |                       |                       |                       |                       | Become Invalid        |
   +=======================+=======================+=======================+=======================+=======================+
   | Layer 4               | TCP or UDP            | **Source IP           | -  Default: 20        | -  Source IP          |
   |                       |                       | address**: The source |    minutes            |    addresses of the   |
   |                       |                       | IP address of each    | -  Maximum: 1 hour    |    clients change.    |
   |                       |                       | request is calculated | -  Range: 1 minute to | -  The session        |
   |                       |                       | using the consistent  |    60 minutes         |    stickiness         |
   |                       |                       | hashing algorithm to  |                       |    duration has been  |
   |                       |                       | obtain a unique hash  |                       |    reached.           |
   |                       |                       | key, and all backend  |                       |                       |
   |                       |                       | servers are numbered. |                       |                       |
   |                       |                       | The system allocates  |                       |                       |
   |                       |                       | the client to a       |                       |                       |
   |                       |                       | particular server     |                       |                       |
   |                       |                       | based on the          |                       |                       |
   |                       |                       | generated key. This   |                       |                       |
   |                       |                       | enables requests from |                       |                       |
   |                       |                       | different clients to  |                       |                       |
   |                       |                       | be routed and ensures |                       |                       |
   |                       |                       | that a client is      |                       |                       |
   |                       |                       | directed to the same  |                       |                       |
   |                       |                       | server that it was    |                       |                       |
   |                       |                       | using previously.     |                       |                       |
   +-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | Layer 7               | HTTP or HTTPS         | -  **Load balancer    | -  Default: 20        | -  If requests sent   |
   |                       |                       |    cookie**: The load |    minutes            |    by the clients do  |
   |                       |                       |    balancer generates | -  Maximum: 24 hours  |    not contain a      |
   |                       |                       |    a cookie after     | -  Range: 1 minute to |    cookie, sticky     |
   |                       |                       |    receiving a        |    1,440 minutes      |    sessions will not  |
   |                       |                       |    request from the   |                       |    take effect.       |
   |                       |                       |    client. All        |                       | -  The session        |
   |                       |                       |    subsequent         |                       |    stickiness         |
   |                       |                       |    requests with the  |                       |    duration has been  |
   |                       |                       |    same cookie are    |                       |    reached.           |
   |                       |                       |    then routed to the |                       |                       |
   |                       |                       |    same backend       |                       |                       |
   |                       |                       |    server.            |                       |                       |
   |                       |                       | -  **Application      |                       |                       |
   |                       |                       |    cookie**: The      |                       |                       |
   |                       |                       |    application        |                       |                       |
   |                       |                       |    deployed on the    |                       |                       |
   |                       |                       |    backend server     |                       |                       |
   |                       |                       |    generates a cookie |                       |                       |
   |                       |                       |    after receiving    |                       |                       |
   |                       |                       |    the first request  |                       |                       |
   |                       |                       |    from the client.   |                       |                       |
   |                       |                       |    All requests with  |                       |                       |
   |                       |                       |    the same cookie    |                       |                       |
   |                       |                       |    generated by       |                       |                       |
   |                       |                       |    backend            |                       |                       |
   |                       |                       |    application are    |                       |                       |
   |                       |                       |    then routed to the |                       |                       |
   |                       |                       |    same backend       |                       |                       |
   |                       |                       |    server.            |                       |                       |
   +-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+

Dedicated load balancers support two types of sticky sessions: **Source IP address** and **Load balancer cookie**

Shared load balancers support three types of sticky session, including **Source IP address**, **Load balancer cookie**, and **Application cookie**.

Classic load balancers support **Source IP address**.

|image1|

Classic load balancers can no longer be created on the management console. Use shared load balancers or dedicated load balancers instead.

Enabling Sticky Sessions
------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image2| and select the desired region and project.

#. Hover on |image3| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. For a shared load balancer and a dedicated load balancer, click **Backend Server Groups**, locate the backend server group, and click |image4| on the right of its name.

   For a classic load balancer, click **Listeners**, locate the listener, and click **Modify** in the **Operation** column.

#. Enable **Sticky Session**, select the sticky session type, and set the session stickiness duration.

#. Click **OK**.

|image5|

You can also configure sticky sessions when adding a listener or creating a backend server group.

.. |image1| image:: /images/note_3.0-en-us.png
.. |image2| image:: /images/en-us_image_0241356603.png

.. |image3| image:: /images/en-us_image_0000001120894978.png

.. |image4| image:: /images/en-us_image_0167649598.png

.. |image5| image:: /images/note_3.0-en-us.png
