:original_name: elb_ug_jt_0023.html

.. _elb_ug_jt_0023:

Forwarding Policy (Dedicated Load Balancers)
============================================

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

#. Click **Add** on the right of **Forwarding Policies**. Configure the parameters based on :ref:`Table 1 <elb_ug_jt_0023__table1569805974113>`.

   .. _elb_ug_jt_0023__table1569805974113:

   .. table:: **Table 1** Parameters required for configuring a forwarding policy

      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+
      | Parameter             | Description                                                                                                                           | Example Value          |
      +=======================+=======================================================================================================================================+========================+
      | Name                  | Specifies the forwarding policy name.                                                                                                 | forwarding_policy-e370 |
      |                       |                                                                                                                                       |                        |
      |                       | Only letters, digits, underscores (_), hyphens (-), and periods (.) are supported.                                                    |                        |
      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+
      | Domain Name           | Route requests based on the domain name. The domain name in the request must exactly match that in the forwarding policy.             | www.test.com           |
      |                       |                                                                                                                                       |                        |
      |                       | Note that you must specify either a domain name or URL.                                                                               |                        |
      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+
      | URL Matching Rule     | There are three URL matching rules:                                                                                                   | Exact match            |
      |                       |                                                                                                                                       |                        |
      |                       | -  Exact match                                                                                                                        |                        |
      |                       |                                                                                                                                       |                        |
      |                       |    The request URL is identical to the URL specified in the forwarding policy.                                                        |                        |
      |                       |                                                                                                                                       |                        |
      |                       | -  Prefix match                                                                                                                       |                        |
      |                       |                                                                                                                                       |                        |
      |                       |    The requested URL starts with the specified URL string.                                                                            |                        |
      |                       |                                                                                                                                       |                        |
      |                       | -  Regular expression match                                                                                                           |                        |
      |                       |                                                                                                                                       |                        |
      |                       |    The specified URL matches the URL in the request based on the regular expression.                                                  |                        |
      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+
      | URL                   | Specifies the relative URL for traffic routing. The load balancer routes traffic based on the combination of the domain name and URL. | /login.php             |
      |                       |                                                                                                                                       |                        |
      |                       | The URL can contain only letters, digits, and special characters \_~?;@^- ``%#&$.*+?,=!:|\/()[]{}``                                   |                        |
      |                       |                                                                                                                                       |                        |
      |                       | If **Exact match** or **Prefix match** is selected, the URL must start with a slash (/).                                              |                        |
      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+
      | Description           | Provides supplementary information about the forwarding policy.                                                                       | ``-``                  |
      |                       |                                                                                                                                       |                        |
      |                       | You can enter up to 255 characters.                                                                                                   |                        |
      +-----------------------+---------------------------------------------------------------------------------------------------------------------------------------+------------------------+

#. Click **Next** and add a backend server group.

   :ref:`Table 2 <elb_ug_jt_0011__table02842501376>` describes the parameters required for adding a backend server group, and :ref:`Table 3 <elb_ug_jt_0011__table172911502712>` describes the parameters required for configuring health check.

#. Click **Finish**.

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
#. In the upper left corner of the page, click |image3| and select the desired region and project.
#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. Click |image5| on the right of **Forwarding Policies**.
#. Modify the parameters and click **OK**.

Deleting a Forwarding Policy
----------------------------

You can delete a forwarding policy if you no longer need it.

Deleted forwarding policies cannot be recovered.

#. Log in to the management console.
#. In the upper left corner of the page, click |image6| and select the desired region and project.
#. Hover on |image7| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. Click |image8| on the right of **Forwarding Policies**.
#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001120894978.png
.. |image5| image:: /_static/images/en-us_image_0000001203245516.png
.. |image6| image:: /_static/images/en-us_image_0000001211126503.png
.. |image7| image:: /_static/images/en-us_image_0000001120894978.png
.. |image8| image:: /_static/images/en-us_image_0000001202965458.png
