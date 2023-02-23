:original_name: elb_ug_jt_0023.html

.. _elb_ug_jt_0023:

Forwarding Policy (Dedicated Load Balancers)
============================================

If advanced forwarding is not enabled, perform the following operations to add forwarding policies to HTTP or HTTPS listeners of dedicated load balancers.

Scenarios
---------

You can add forwarding policies to HTTP or HTTPS listeners to forward requests to different backend server groups based on domain names or URLs.

This is suited for applications that are deployed on multiple backend servers and provide multiple types of services such as videos, images, audios, and texts.

A forwarding policy consists of one or more forwarding rules and an action.

-  There are two types of forwarding rules: domain name and URL.
-  There are two types of actions: forward to a backend server group and redirect to another listener (only HTTP listeners).

Constraints and Limitations
---------------------------

-  Forwarding policies can be added only to HTTP and HTTPS listeners.
-  Redirection to another listener is supported only by HTTP listeners.
-  When you add a forwarding policy, note the following:

   -  Each URL path must exist on the backend server. If the path does not exist, the backend server will return 404 Not Found.
   -  A URL path cannot be configured for two forwarding policies.
   -  In the regular expression match, the characters are matched sequentially, and matching ends when any rule is successfully matched. Matching rules cannot overlap with each other.
   -  A domain name cannot exceed 100 characters.

-  After you add a forwarding policy, the load balancer forwards requests based on the specified domain name or URL:

   -  If the domain name or URL in a request matches that specified in the forwarding policy, the request is forwarded to the backend server group you select when you add the forwarding policy.
   -  If the domain name or URL in a request does not match that specified in the forwarding policy, the request is forwarded to the default backend server group of the listener.

Adding a Forwarding Policy
--------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image3| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** on the right of the page.

#. On the **Forwarding Policies** tab page, click **Add Forwarding Policy**. Configure the parameters based on :ref:`Table 1 <elb_ug_jt_0023__elb_ug_jt_0023_table10859681016>`.

#. Click Save.

.. _elb_ug_jt_0023__elb_ug_jt_0023_table10859681016:

.. table:: **Table 1** Forwarding policy parameters

   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   | Parameter            |                                   | Description                                                                                                                                                                                                                                                                              | Example Value                     |
   +======================+===================================+==========================================================================================================================================================================================================================================================================================+===================================+
   | Forwarding Rule      | Domain Name                       | Route requests based on the domain name. The domain name in the request must exactly match that in the forwarding policy.                                                                                                                                                                | www.test.com                      |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | You need to specify either a domain name or URL.                                                                                                                                                                                                                                         |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | .. note::                                                                                                                                                                                                                                                                                |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    Advanced forwarding policies support wildcard domain names. For details, see :ref:`Advanced Forwarding <elb_ug_jt_060300>`.                                                                                                                                                           |                                   |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   |                      | URL                               | Route requests based on the URL. There are three URL matching rules:                                                                                                                                                                                                                     | /login.php                        |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | -  Exact match                                                                                                                                                                                                                                                                           |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    The request URL is identical to the URL specified in the forwarding policy.                                                                                                                                                                                                           |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | -  Prefix match                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    The requested URL starts with the specified URL string.                                                                                                                                                                                                                               |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | -  Regular expression match                                                                                                                                                                                                                                                              |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    The requested URL matches the specified URL string based on the regular expression.                                                                                                                                                                                                   |                                   |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   | Action               | Forward to a backend server group | If the request matches the configured forwarding rule, the request is forwarded to the specified backend server group.                                                                                                                                                                   | Forward to a backend server group |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   |                      | Redirect to another listener      | If the request matches the configured forwarding rule, the request is redirected to the specified HTTPS listener.                                                                                                                                                                        | ``-``                             |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | This action can be configured only for HTTP listeners.                                                                                                                                                                                                                                   |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | .. note::                                                                                                                                                                                                                                                                                |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    If you select **Redirect to another listener** and create a redirect for the current listener, this listener will not route requests and will redirect the requests to the specified HTTPS listener, but access control configured for the listener will still take effect.           |                                   |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   |    For example, if you configure a redirect for an HTTP listener, HTTP requests to access a web page will be redirected to the HTTPS listener you select and handled by the backend servers associated with the HTTPS listener. As a result, the clients access the web page over HTTPS. |                                   |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   | Backend Server Group |                                   | Select a backend server group that will receive requests from the load balancer.                                                                                                                                                                                                         | ``-``                             |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | This parameter is mandatory when you set **Action** to **Forward to a backend server group**.                                                                                                                                                                                            |                                   |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+
   | Listener             |                                   | Select an HTTPS listener that will receive requests redirected from the current HTTP listener.                                                                                                                                                                                           | ``-``                             |
   |                      |                                   |                                                                                                                                                                                                                                                                                          |                                   |
   |                      |                                   | This parameter is mandatory when **Action** is set to **Redirect to another listener**.                                                                                                                                                                                                  |                                   |
   +----------------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------+

URL Matching Example
--------------------

The following table lists how a URL is matched, and :ref:`Figure 1 <elb_ug_jt_0023__fig87121434403>` shows how a request is forwarded to a backend server group.

.. table:: **Table 2** URL matching

   +--------------------------+-----------------+------------------------------+-------+--------------+-------------+
   | URL Matching Rule        | URL             | URL in the Forwarding Policy |       |              |             |
   +==========================+=================+==============================+=======+==============+=============+
   | ``-``                    | ``-``           | /elb/index.html              | /elb  | /elb[^\\s]\* | /index.html |
   +--------------------------+-----------------+------------------------------+-------+--------------+-------------+
   | Exact match              | /elb/index.html | Y                            | ``-`` | ``-``        | ``-``       |
   +--------------------------+-----------------+------------------------------+-------+--------------+-------------+
   | Prefix match             |                 | Y                            | Y     | ``-``        | ``-``       |
   +--------------------------+-----------------+------------------------------+-------+--------------+-------------+
   | Regular expression match |                 | Y                            | ``-`` | Y            | ``-``       |
   +--------------------------+-----------------+------------------------------+-------+--------------+-------------+

.. _elb_ug_jt_0023__fig87121434403:

.. figure:: /_static/images/en-us_image_0000001080630400.jpg
   :alt: **Figure 1** Request forwarding

   **Figure 1** Request forwarding

In this figure, the system first searches for an exact match of the requested URL (/elb_gls/glossary.html). If there is no exact match, the system searches for a prefix match. If a match is found, the request is forwarded to backend server group 2 even if a regular expression match is also found, because the prefix match has a higher priority.

Modifying a Forwarding Policy
-----------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image4| and select the desired region and project.

#. Hover on |image5| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image6| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** in the right pane.

#. On the **Forwarding Policies** tab page, select the forwarding policy you want to modify and click **Edit**.

#. Modify the parameters and click Save.

Deleting a Forwarding Policy
----------------------------

You can delete a forwarding policy if you no longer need it.

Deleted forwarding policies cannot be recovered.

#. Log in to the management console.

#. In the upper left corner of the page, click |image7| and select the desired region and project.

#. Hover on |image8| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image9| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** in the right pane.

#. On the **Forwarding Policies** tab page, select the forwarding policy you want to delete and click **Delete**.

#. In the displayed dialog box, click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001417088430.png
.. |image3| image:: /_static/images/en-us_image_0000001127832787.png
.. |image4| image:: /_static/images/en-us_image_0000001211126503.png
.. |image5| image:: /_static/images/en-us_image_0000001417088430.png
.. |image6| image:: /_static/images/en-us_image_0000001127715643.png
.. |image7| image:: /_static/images/en-us_image_0000001211126503.png
.. |image8| image:: /_static/images/en-us_image_0000001417088430.png
.. |image9| image:: /_static/images/en-us_image_0000001127598405.png
