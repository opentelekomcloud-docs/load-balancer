:original_name: elb_ug_jt_060303.html

.. _elb_ug_jt_060303:

Configuring Advanced Forwarding
===============================

Scenarios
---------

You can add advanced forwarding policies to HTTP or HTTPS listeners of dedicated load balancers to route requests more specifically.

Each advanced forwarding policy consists of one or more forwarding rules and an action.

-  Dedicated load balancers support the following types of forwarding rules: domain name, URL, HTTP request method, HTTP header, query string, and CIDR block (source IP addresses). For details, see :ref:`Forwarding Rule Types <elb_ug_jt_060302__en-us_topic_0000001182135225_section1351817374499>`.
-  There are four types of actions: forward to a backend server group, redirect to another listener, redirect to another URL, and return a specific response body. For details, see :ref:`Action Types <elb_ug_jt_060302__en-us_topic_0000001182135225_section107001685017>`.
-  Wildcard domain names are allowed.
-  Multiple forwarding rules can be configured in a single forwarding policy.
-  Forwarding policies can be sorted based on their priorities.

Constraints and Limitations
---------------------------

-  Advanced forwarding cannot be disabled once enabled.
-  A maximum of 100 forwarding policies can be configured for a listener. If the number of forwarding policies exceeds the quota, the excess forwarding policies will not be applied.
-  An advanced forwarding policy can contain a maximum of 10 conditions.

Enabling Advanced Forwarding
----------------------------

#. Log in to the management console.
#. In the upper left corner of the page, click |image1| and select the desired region and project.
#. Hover on |image2| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.
#. Locate the load balancer and click its name.
#. Click **Listeners**, locate the listener, and click its name.
#. In the **Basic Information** tab page of the listener in the right pane, click **Enable** next to **Advanced Forwarding**.
#. Click **OK**.

Adding an Advanced Forwarding Policy
------------------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image3| and select the desired region and project.

#. Hover on |image4| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image5| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** on the right of the page.

#. On the **Forwarding Policies** tab page, click **Add Forwarding Policy**.

   Configure the parameters based on :ref:`Table 1 <elb_ug_jt_060303__en-us_topic_0000001168961119_en-us_topic_0000001127292335_table10859681016>`.

#. Click **Save**.

.. _elb_ug_jt_060303__en-us_topic_0000001168961119_en-us_topic_0000001127292335_table10859681016:

.. table:: **Table 1** Forwarding policy parameters

   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   | Parameter       |                                   | Description                                                                                                                                                                                                                                                                                                                                          | Example Value                                      |
   +=================+===================================+======================================================================================================================================================================================================================================================================================================================================================+====================================================+
   | Forwarding Rule | Domain name                       | Route requests based on the domain name. Exact match domains and wildcard domains are supported.                                                                                                                                                                                                                                                     | www.example.com                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  You can configure multiple domain names in a forwarding policy.                                                                                                                                                                                                                                                                                   |                                                    |
   |                 |                                   | -  A domain name contains at least two labels separated by periods (.). Each label can contain letters, digits, hyphens (-), periods (.), and asterisks (*), must start with a letter, digit, or asterisk (*), and cannot end with a hyphen (-). An asterisk (*) must be used as the leftmost label if you want to configure a wildcard domain name. |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | URL                               | Route requests based on the URLs.                                                                                                                                                                                                                                                                                                                    | Request URL: /login.php                            |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  You can configure multiple URLs in a forwarding policy.                                                                                                                                                                                                                                                                                           | -  Exact match: /login.php                         |
   |                 |                                   | -  A URL can contain letters, digits, and special characters \_-';@^- ``%#$.*+?,=!:|\/()[]{}.`` In exact match and prefix match, the URL must start with a slash (/).                                                                                                                                                                                |                                                    |
   |                 |                                   | -  There are three URL matching rules:                                                                                                                                                                                                                                                                                                               | -  Prefix match: /log                              |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      | -  Regular expression match: /(\\w)*\\.php         |
   |                 |                                   |    -  **Exact match**                                                                                                                                                                                                                                                                                                                                |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |       The request URL is identical to the URL specified in the forwarding policy.                                                                                                                                                                                                                                                                    |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    -  **Prefix match**                                                                                                                                                                                                                                                                                                                               |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |       The requested URL starts with the specified URL string.                                                                                                                                                                                                                                                                                        |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    -  **Regular expression match**                                                                                                                                                                                                                                                                                                                   |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |       The requested URL matches the specified URL string based on the regular expression.                                                                                                                                                                                                                                                            |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | HTTP request method               | Route requests based on any HTTP method. The following methods are available: **GET**, **POST**, **PUT**, **DELETE**, **PATCH**, **HEAD**, and **OPTIONS**.                                                                                                                                                                                          | GET                                                |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | You can configure multiple request methods in a forwarding policy.                                                                                                                                                                                                                                                                                   |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | HTTP header                       | Route requests based on the HTTP header.                                                                                                                                                                                                                                                                                                             | -  Key: Accept-Language                            |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      | -  Value: en-us                                    |
   |                 |                                   | An HTTP header consists of a key and one or more values. You need to configure the key and values separately.                                                                                                                                                                                                                                        |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  The key can contain only letters, digits, underscores (_), and hyphens (-).                                                                                                                                                                                                                                                                       |                                                    |
   |                 |                                   | -  Each value can contain only letters, digits, and special characters !#$ ``%&'()*+,`` .\\/:;<=>?@[]^-_'{|}-                                                                                                                                                                                                                                        |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | Query string                      | Route requests based on the query string.                                                                                                                                                                                                                                                                                                            | -  Key: locale                                     |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      | -  Value: en-us                                    |
   |                 |                                   | A query string consists of a key and one or more values. You need to set the key and values separately.                                                                                                                                                                                                                                              |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  The key can contain only letters, digits, and the following special characters ``!$'()*+,`` ./:;=?@^-_'                                                                                                                                                                                                                                           |                                                    |
   |                 |                                   | -  Each value can contain only letters, digits, and special characters ``!$'()*+,`` ./:;=?@^-_'                                                                                                                                                                                                                                                      |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | CIDR block                        | Route requests based on the source IP addresses.                                                                                                                                                                                                                                                                                                     | 192.168.1.0/24                                     |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   | Action          | Forward to a backend server group | Requests are forwarded to the specified backend server group.                                                                                                                                                                                                                                                                                        | Forward to a backend server group                  |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | Redirect to another listener      | Forwards requests from the HTTP listener to an HTTPS listener.                                                                                                                                                                                                                                                                                       | ``-``                                              |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | .. note::                                                                                                                                                                                                                                                                                                                                            |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    If you select **Redirect to another listener** and create a redirect for the current listener, this listener will not route requests and will redirect the requests to the specified HTTPS listener, but access control configured for the listener will still take effect.                                                                       |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    For example, if you configure a redirect for an HTTP listener, HTTP requests to access a web page will be redirected to the HTTPS listener you select and handled by the backend servers associated with the HTTPS listener. As a result, the clients access the web page over HTTPS.                                                             |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | Redirect to another URL           | Requests are redirected to the configured URL.                                                                                                                                                                                                                                                                                                       | Protocol: HTTP                                     |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | When clients access website A, the load balancer returns 302 or any other 3xx status code and automatically redirects the clients to website B. You can custom the redirection URL that will be returned to the clients.                                                                                                                             | Domain name: www.example1.com                      |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | A URL consists of the following parameters:                                                                                                                                                                                                                                                                                                          | Port: 8081                                         |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **Protocol**: ${protocol}, HTTP, or HTTPS                                                                                                                                                                                                                                                                                                         | Path: /index.html                                  |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    ${protocol}: retains the protocol of the request.                                                                                                                                                                                                                                                                                                 | Query string: locale=en-us                         |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **Domain Name**: A domain name consists of at least two labels separated by periods (.). Each label can contain only letters, digits, hyphens (-), and dots (.), must start with a letter, digit, or asterisk (*), and cannot end with a hyphen (-).                                                                                              | HTTP status code: 301                              |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    ${host}: retains the domain name of the request.                                                                                                                                                                                                                                                                                                  |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **Port**: ranges from 1 to 65535.                                                                                                                                                                                                                                                                                                                 |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    ${port}: retains the port number of the request.                                                                                                                                                                                                                                                                                                  |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **Path**: A path can contain letters, digits, and special characters \_-';@^- ``%#&$.*+?,=!:|\/()[]{}`` and must start with a slash (/).                                                                                                                                                                                                          |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    ${path}: retains the path of the request.                                                                                                                                                                                                                                                                                                         |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **Query String**: A query string can contain only letters, digits, and the following special characters ``!$'()*+,`` ./:;=?@&^-_', and & can only be used as a separator.                                                                                                                                                                         |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **HTTP Status Code**: 301, 302, 303, 307, or 308                                                                                                                                                                                                                                                                                                  |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | .. note::                                                                                                                                                                                                                                                                                                                                            |                                                    |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   |    Specify either the above parameters or a combination of them.                                                                                                                                                                                                                                                                                     |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+
   |                 | Return a specific response body   | Load balancers return a fixed response to the clients.                                                                                                                                                                                                                                                                                               | HTTP Status Code: 200                              |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | You can custom the status code and response body that load balancers directly return to the clients without the need to route the requests to backend servers.                                                                                                                                                                                       | Content-Type: text/plain                           |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | A response body consists of the following parameters:                                                                                                                                                                                                                                                                                                | Message Body: The server can be accessed normally. |
   |                 |                                   |                                                                                                                                                                                                                                                                                                                                                      |                                                    |
   |                 |                                   | -  **HTTP Status Code**: Only 2xx, 4xx, and 5xx status codes are supported.                                                                                                                                                                                                                                                                          |                                                    |
   |                 |                                   | -  **Content-Type**: text/plain, text/css, text/html, application/javascript, or application/json                                                                                                                                                                                                                                                    |                                                    |
   |                 |                                   | -  **Message Body**: This parameter is optional.                                                                                                                                                                                                                                                                                                     |                                                    |
   +-----------------+-----------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+----------------------------------------------------+

Sorting Forwarding Policies
---------------------------

Multiple forwarding policies can be sorted to set their priorities.

#. Log in to the management console.

#. In the upper left corner of the page, click |image6| and select the desired region and project.

#. Hover on |image7| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image8| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** in the right pane.

#. On the **Forwarding Policies** tab page, click **Sort**.

#. Click **Up** or **Down** in the upper right corner of the forwarding policy.

#. Click **Save**.

URL Matching Examples
---------------------

:ref:`Table 2 <elb_ug_jt_060303__table39051294411>` shows how URLs configured in the forwarding policies match the URLs in the requests.

.. _elb_ug_jt_060303__table39051294411:

.. table:: **Table 2** URL matching

   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+
   | Request URL     | Forwarding Policy    | URL in the Forwarding Policy | Matching Mode            | Forwarding Policy Priority | Forward to a backend server group |
   +=================+======================+==============================+==========================+============================+===================================+
   | /elb/abc.html   | Forwarding policy 01 | /elb/abc.html                | Prefix match             | 1                          | Backend server group 01           |
   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+
   |                 | Forwarding policy 02 | /elb                         | Prefix match             | 2                          | Backend server group 02           |
   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+
   | /exa/index.html | Forwarding policy 03 | /exa[^\\s]\*                 | Regular expression match | 3                          | Backend server group 03           |
   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+
   |                 | Forwarding policy 04 | /exa/index.html              | Regular expression match | 4                          | Backend server group 04           |
   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+
   | /mpl/index.html | Forwarding policy 05 | /mpl/index.html              | Exact match              | 5                          | Backend server group 05           |
   +-----------------+----------------------+------------------------------+--------------------------+----------------------------+-----------------------------------+

URLs are matched as follows:

-  When the request URL is /elb/abc.html, it matches both forwarding policy 01 and forwarding policy 02. However, the priority of forwarding policy 01 is higher than that of forwarding policy 02. Forwarding policy 01 is used, and requests are forwarded to backend server group 01.
-  When the request URL is /exa/index.html, it matches both forwarding policy 03 and forwarding policy 04. However, the priority of forwarding policy 03 is higher than that of forwarding policy 04. Forwarding policy 03 is used, and requests are forwarded to backend server group 03.
-  If the request URL is /mpl/index.html, it matches forwarding policy 05 exactly, and requests are forwarded to backend server group 05.

Modifying a Forwarding Policy
-----------------------------

#. Log in to the management console.

#. In the upper left corner of the page, click |image9| and select the desired region and project.

#. Hover on |image10| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image11| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** in the right pane.

#. On the **Forwarding Policies** tab page, select the forwarding policy you want to modify and click **Edit**.

#. Modify the parameters and click **Save**.

Deleting a Forwarding Policy
----------------------------

You can delete a forwarding policy if you no longer need it.

Deleted forwarding policies cannot be recovered.

#. Log in to the management console.

#. In the upper left corner of the page, click |image12| and select the desired region and project.

#. Hover on |image13| in the upper left corner to display **Service List** and choose **Network** > **Elastic Load Balancing**.

#. Locate the load balancer and click its name.

#. Click **Listeners**, locate the listener, and click its name.

#. Click |image14| on the right of the listener name and select **Configure Forwarding Policy**.

   Alternatively, click **Forwarding Policies** in the right pane.

#. On the **Forwarding Policies** tab page, select the forwarding policy you want to delete and click **Delete**.

#. In the displayed dialog box, click **Yes**.

.. |image1| image:: /_static/images/en-us_image_0000001747739624.png
.. |image2| image:: /_static/images/en-us_image_0000001794660485.png
.. |image3| image:: /_static/images/en-us_image_0000001747739624.png
.. |image4| image:: /_static/images/en-us_image_0000001794660485.png
.. |image5| image:: /_static/images/en-us_image_0000001747739992.png
.. |image6| image:: /_static/images/en-us_image_0000001747739624.png
.. |image7| image:: /_static/images/en-us_image_0000001794660485.png
.. |image8| image:: /_static/images/en-us_image_0000001747739984.png
.. |image9| image:: /_static/images/en-us_image_0000001747739624.png
.. |image10| image:: /_static/images/en-us_image_0000001794660485.png
.. |image11| image:: /_static/images/en-us_image_0000001747381100.png
.. |image12| image:: /_static/images/en-us_image_0000001747739624.png
.. |image13| image:: /_static/images/en-us_image_0000001794660485.png
.. |image14| image:: /_static/images/en-us_image_0000001794660837.png
