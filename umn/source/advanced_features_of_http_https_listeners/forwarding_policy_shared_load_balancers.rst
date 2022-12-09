:original_name: en-us_topic_0114694934.html

.. _en-us_topic_0114694934:

Forwarding Policy (Shared Load Balancers)
=========================================

Scenarios
---------

You can add forwarding policies to HTTP or HTTPS listeners to forward requests to different backend server groups based on domain names or URLs.

This is suited for applications that are deployed on multiple backend servers and provide multiple types of services such as videos, images, audios, and texts.

A forwarding policy consists of a forwarding rule and an action.

-  There are two types of forwarding rules: domain name and URL.
-  The only supported action is to forward requests to a backend server group.

Constraints and Limitations
---------------------------

-  Forwarding policies can be added only to HTTP and HTTPS listeners.
-  When you add a forwarding policy, note the following:

   -  Each URL path must exist on the backend server. If the path does not exist, the backend server will return 404 Not Found.
   -  A URL path cannot be configured for two forwarding policies.
   -  In the regular expression match, the characters are matched sequentially, and matching ends when any rule is successfully matched. Matching rules cannot overlap with each other.

-  After you add a forwarding policy, the load balancer forwards requests based on the specified domain name or URL:

   -  If the domain name or URL in a request matches that specified in the forwarding policy, the request is forwarded to the backend server group you select or create when you add the forwarding policy.
   -  If the domain name or URL in a request does not match that specified in the forwarding policy, the request is forwarded to the default backend server group of the listener.

.. caution::

   If you add a forwarding policy that is the same as an existing one, there will be a conflict. Even if you delete the existing forwarding policy, the newly-added forwarding policy is still in the **Faulty** state. Delete the newly-added forwarding policy and add a different one.

Adding a Forwarding Policy
--------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image1| and select the desired region and project.

#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click **Add** on the right of **Forwarding Policies**.

#. In the **Add Forwarding Policy** dialog box, configure the parameters based on :ref:`Table 1 <en-us_topic_0114694934__table10859681016>`.

#. Click **OK**.

   Alternatively, locate the load balancer in the load balancer list and click the name of the listener in the **Listener** column. In the **Listeners** area, click **Add** on the right of **Forwarding Policies** and then add a forwarding policy.

.. _en-us_topic_0114694934__table10859681016:

.. table:: **Table 1** Forwarding policy parameters

   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   | Item                        | Parameter            | Description                                                                                                                                                                                                        | Example Value          |
   +=============================+======================+====================================================================================================================================================================================================================+========================+
   | Configure Forwarding Policy | Name                 | Specifies the forwarding policy name.                                                                                                                                                                              | forwarding_policy-q582 |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   |                             | Domain Name          | Specifies the domain name used for forwarding requests. The domain name in the request must exactly match that in the forwarding policy. You need to specify either a domain name or URL.                          | www.test.com           |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   |                             | URL Matching Rule    | -  **Exact match**                                                                                                                                                                                                 | Exact match            |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      |    The request URL is identical to the preset URL.                                                                                                                                                                 |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      | -  **Prefix match**                                                                                                                                                                                                |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      |    The requested URL starts with the specified URL string.                                                                                                                                                         |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      | -  **Regular expression match**                                                                                                                                                                                    |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      |    The requested URL matches the specified URL string based on the regular expression.                                                                                                                             |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      |    .. note::                                                                                                                                                                                                       |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      |       -  **Exact match** has the highest priority, followed by **Prefix match**. **Regular expression match** has the lowest priority.                                                                             |                        |
   |                             |                      |       -  If you use prefix match, the longest string is chosen. For example, if there are two preset URLs **/elb** and **/elbvip** and the accessed URL is **/elbvipplus**, **/elbvip** is preferentially matched. |                        |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   |                             | URL                  | Specifies the URL used for forwarding requests.                                                                                                                                                                    | /login.php             |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   |                             | Description          | Provides supplementary information about the forwarding policy.                                                                                                                                                    | N/A                    |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+
   | Add Backend Server Group    | Backend Server Group | Specifies whether you want a new backend server group or an existing backend server group.                                                                                                                         | Create new             |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      | If you select **Create new**, configure the parameters based on :ref:`Table 1 <en-us_topic_0052569729__table299811529239>` and :ref:`Table 2 <en-us_topic_0052569729__table1022053182319>`.                        |                        |
   |                             |                      |                                                                                                                                                                                                                    |                        |
   |                             |                      | If you select **Use existing**, select an existing backend server group.                                                                                                                                           |                        |
   +-----------------------------+----------------------+--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+------------------------+

URL Matching Example
--------------------

The following table lists how a URL is matched, and :ref:`Figure 1 <en-us_topic_0114694934__fig87121434403>` shows how a request is forwarded to a backend server group.

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

.. _en-us_topic_0114694934__fig87121434403:

.. figure:: /_static/images/en-us_image_0114721717.jpg
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
#. Click **Forwarding Policies**.
#. Locate the forwarding policy and click |image5| on the right of its name.
#. In the **Modify Forwarding Policy** dialog box, modify the parameters and click **OK**.

Deleting a Forwarding Policy
----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image6| and select the desired region and project.
#. Hover on |image7| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. Click **Forwarding Policies**.
#. Locate the forwarding policy and click |image8| on the right of its name.
#. Click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001211126503.png
.. |image2| image:: /_static/images/en-us_image_0000001120894978.png
.. |image3| image:: /_static/images/en-us_image_0000001211126503.png
.. |image4| image:: /_static/images/en-us_image_0000001120894978.png
.. |image5| image:: /_static/images/en-us_image_0238446941.png
.. |image6| image:: /_static/images/en-us_image_0000001211126503.png
.. |image7| image:: /_static/images/en-us_image_0000001120894978.png
.. |image8| image:: /_static/images/en-us_image_0238447292.png
