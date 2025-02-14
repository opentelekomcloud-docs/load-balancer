:original_name: ListApiVersions.html

.. _ListApiVersions:

Querying API Versions
=====================

Function
--------

This API is used to query all available ELB API versions.

URI
---

GET /versions

Request Parameters
------------------

None

Response Parameters
-------------------

**Status code: 200**

.. table:: **Table 1** Response body parameters

   +-----------+-----------------------------------------------------------------------------------+-----------------------------------+
   | Parameter | Type                                                                              | Description                       |
   +===========+===================================================================================+===================================+
   | versions  | Array of :ref:`ApiVersionInfo <listapiversions__response_apiversioninfo>` objects | Lists the available API versions. |
   +-----------+-----------------------------------------------------------------------------------+-----------------------------------+

.. _listapiversions__response_apiversioninfo:

.. table:: **Table 2** ApiVersionInfo

   +-----------------------+-----------------------+------------------------------------------------------------------+
   | Parameter             | Type                  | Description                                                      |
   +=======================+=======================+==================================================================+
   | id                    | String                | Specifies the API version.                                       |
   |                       |                       |                                                                  |
   |                       |                       | The value can be **v3**, **v2**, or **v2.0** in ascending order. |
   +-----------------------+-----------------------+------------------------------------------------------------------+
   | status                | String                | Specifies the status of the API version.                         |
   |                       |                       |                                                                  |
   |                       |                       | The values are as follows:                                       |
   |                       |                       |                                                                  |
   |                       |                       | -  **CURRENT**: current version                                  |
   |                       |                       |                                                                  |
   |                       |                       | -  **STABLE**: stable version                                    |
   |                       |                       |                                                                  |
   |                       |                       | -  **DEPRECATED**: discarded version                             |
   |                       |                       |                                                                  |
   |                       |                       | Note: **CURRENT** indicates the latest version.                  |
   +-----------------------+-----------------------+------------------------------------------------------------------+

Example Requests
----------------

Querying API versions

.. code-block:: text

   GET https://{ELB_Endpoint}/versions

Example Responses
-----------------

**Status code: 200**

Successful request.

.. code-block::

   {
     "versions" : [ {
       "id" : "v3",
       "status" : "CURRENT"
     }, {
       "id" : "v2",
       "status" : "STABLE"
     }, {
       "id" : "v2.0",
       "status" : "STABLE"
     } ]
   }

Status Codes
------------

=========== ===================
Status Code Description
=========== ===================
200         Successful request.
=========== ===================

Error Codes
-----------

See :ref:`Error Codes <errorcode>`.
